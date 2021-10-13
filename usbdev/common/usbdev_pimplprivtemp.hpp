/* ///////////////////////////////////////////////////////////////////// */
/*! 
  @file    PImplPrivTemp.hxx
  @author  night wing
  @date    2017/03
  @brief   The file declare the PImplPriv Template  Protocol
  @par     History
  @verbatim
          <author>   <time>   <version>  <desc>                                   
         nightwing   2018/03   0.1.0     build this module       
  @endverbatim
*/
/* ///////////////////////////////////////////////////////////////////// */
#ifndef  USBDEV_PIMPLPRIVTEMP_HXX
#define  USBDEV_PIMPLPRIVTEMP_HXX


// /////////////////////////////////////////////////////////////////////
//  definition & include
// ///////////////////////////////////////////////////////////////////// 
#include <stdint.h>
#include <atomic> //C++11

#define USBDEV_PImplPrivTemp_PtrCast( t, o ) (  reinterpret_cast< t >( reinterpret_cast< intptr_t >( o ))  )
#define USBDEV_PImplPrivTemp_IntPtrCast( o ) (  reinterpret_cast< intptr_t >( o ))


#ifndef USBDEV_PImplPrivTemp_new
#define USBDEV_PImplPrivTemp_new( t, ... )  ( new t( __VA_ARGS__ ))
#endif

#ifndef USBDEV_PImplPrivTemp_delete
#define USBDEV_PImplPrivTemp_delete( o, t )  do{ delete USBDEV_PImplPrivTemp_PtrCast( t*,  o ); }while(0)
#endif

// /////////////////////////////////////////////////////////////////////
//! PImplPrivTemp
/*!
  This class is used to declare the PIMPL Private Object.
*/
// ///////////////////////////////////////////////////////////////////// 
namespace UsbDev {

template <typename T>
class  PImplPrivTemp  {
public:   
    // =================================================================
    // CTOR/DTOR
    // ================================================================= 
    PImplPrivTemp (  ) { m_ref_cntr.store(1); }
    virtual ~PImplPrivTemp ( ) { }
    
    // =================================================================
    // Functions
    // ================================================================= 
    virtual T*    duplicateIfShared ( void ** );
    
    static T*    buildIfNull ( void **w_obj ); 
    static T*    createInstance ( )           { return USBDEV_PImplPrivTemp_new( T ); }
    static T*    createInstance ( void *ref ) { return USBDEV_PImplPrivTemp_new( T,  * USBDEV_PImplPrivTemp_PtrCast( T*, ref ) ); }
    static T*    addRef    ( void *cd )       {
        if ( cd != nullptr ) {
            USBDEV_PImplPrivTemp_PtrCast( T*, cd )->addRefCntr( );
        }
        return  USBDEV_PImplPrivTemp_PtrCast( T*, cd );
    }
    static bool  releaseRef( void *   );
    static bool  attach    ( void **src_obj, void **dst_obj );

    static T*    instanceCow ( void ** );

protected:
    inline int  addRefCntr( )    { return m_ref_cntr.fetch_add(1) + 1; }
    inline int  releaseRefCntr( ){ return m_ref_cntr.fetch_sub(1) - 1; }
    inline int  currRefCntr( )   { return m_ref_cntr.load(); }

private:
    std::atomic<int>  m_ref_cntr;
};

#define USBDEV_PImplPrivTemp_AttachPtr( t, s, d )\
    t :: attach( USBDEV_PImplPrivTemp_PtrCast( void**, s ), USBDEV_PImplPrivTemp_PtrCast( void**, d ))

#define USBDEV_PImplPrivTemp_BuildIfNull( t, d ) \
    t :: buildIfNull( USBDEV_PImplPrivTemp_PtrCast( void**, d ) )


// =====================================================
//! build an instance if the *w_obj is NULL 
/*!
  @param  w_obj [ in_out ] the object pointer of pointer
  @return a object that created or existed.
  @note   if *w_obj is null, this routine will create one.
*/
// =====================================================
template <typename T >
T*   PImplPrivTemp<T> :: buildIfNull( void **w_obj )
{
    if ( w_obj == nullptr  ) { return nullptr; }
    if ( *w_obj == nullptr ) { *w_obj = PImplPrivTemp<T>::createInstance( ); }
    //return ( T *)( *w_obj );
    return USBDEV_PImplPrivTemp_PtrCast( T*, *w_obj );
}

// =====================================================
//! release the reference or delete it if reference counter is zero
/*!
  @param cd [ in ] the object pointer
  @note  decrease the reference counter, if counter is zero after decreased,\n
         this routine will delete the object pointed by cd.
*/
// =====================================================
template <typename T>
bool  PImplPrivTemp<T> :: releaseRef ( void *cd )
{
    bool is_released = false;
    if ( cd != nullptr ) {
        //if ( (( T *) cd )->releaseRefCntr( ) == 0 ) {
        if ( USBDEV_PImplPrivTemp_PtrCast( T*, cd )->releaseRefCntr() == 0 ) {
            USBDEV_PImplPrivTemp_delete( cd, T );
            is_released = true;
        }
    }   	
    return is_released;
}

// =======================================================
//! duplicate if shared 
/*!
  @param w_obj [ in_out ] the object pointer of pointer
  @return object pointer duplicated or existed
  @note  this routine check the reference counter, if it is not one, \n
         use copy constructor to duplicate a new one, and return it. NOTE: \n
         the *w_obj will be changed if a new object created. \n
         User must implement the COPY CONSTRUCTOR if used this function.
*/
// =======================================================
template <typename T >
T *    PImplPrivTemp<T> :: duplicateIfShared( void **w_obj )
{
    if ( w_obj == nullptr ) { return nullptr; }
    //if ( this->currRefCntr( ) == 1 ) { return ( T *)( *w_obj ); }
    if ( this->currRefCntr( ) == 1 ) { return USBDEV_PImplPrivTemp_PtrCast( T *, *w_obj ); }

    T *new_obj = PImplPrivTemp<T>::createInstance( *w_obj );
    PImplPrivTemp<T>::releaseRef( *w_obj );
    *w_obj = new_obj;
    
    return new_obj;
}	

// ===========================================================
//! attach to an existed object
/*!
  @param src_obj [ in_out ] the source object pointer of pointer
  @param dst_obj [ in     ] the target object pointer of pointer
  @return true for attached, false for an error.
  @note  this routine make the *src_obj attach to *dst_obj.
*/
// ===========================================================
template <typename T >
bool    PImplPrivTemp<T> :: attach ( void **src_obj, void **dst_obj )
{
    // do not attach to self
    if ( src_obj == dst_obj ) { return true; }
    if ( src_obj == nullptr ) { return false; }
    if ( dst_obj != nullptr  &&  *src_obj == *dst_obj ) { return true; } // need not to attach.	

    // free self
    if ( *src_obj != nullptr ) {
        PImplPrivTemp<T>::releaseRef( *src_obj );
        *src_obj = nullptr;
    }
	
    // attach to dst.
    // user maybe use  attach( obj, nullptr ), so check the dst_obj address is needed.
//    if ( dst_obj > ( void **)( 0x100 ) ) {
    intptr_t tmp_ptr = 0x100;
    if ( dst_obj > reinterpret_cast<void**>( tmp_ptr )) {
        if ( *dst_obj != nullptr ) {
            *src_obj = PImplPrivTemp<T>::addRef( *dst_obj );
        }
    }

    return true;
}

// ===========================================================
//! get the instance, and do copy on write if shared
/*!
  @param  w_obj [ in_out ] the object pointer of pointer
  @note   get the instance always successful. Means if instance is \n
          not existed, this routine will create one. Another case if \n
          instance shared with other one, this routine do the deep copy.
*/
// ===========================================================
template <typename T>
T*      PImplPrivTemp<T> :: instanceCow ( void **w_obj )
{
    if ( w_obj == nullptr  ) { return nullptr; }
    if ( *w_obj == nullptr ) { *w_obj = PImplPrivTemp<T>::createInstance( ); }
//    if ( (( T *) *w_obj)->currRefCntr( ) == 1 ) { return ( T *)( *w_obj ); }
    if ( USBDEV_PImplPrivTemp_PtrCast( T*, *w_obj)->currRefCntr( ) == 1 ) {
        return USBDEV_PImplPrivTemp_PtrCast( T*, *w_obj );
    }

    T *new_obj = PImplPrivTemp<T>::createInstance( *w_obj );
    PImplPrivTemp<T>::releaseRef( *w_obj );
    *w_obj = new_obj;

    return new_obj;
}


}



#endif
