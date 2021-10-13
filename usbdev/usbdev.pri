# ==================================================
#
#    This file used in user application 
#
# ==================================================
! contains( USBDEV_PRI, usbdev ) {
    USBDEV_PRI *= usbdev
    CONFIG *= c++11
    INCLUDEPATH *= $$PWD/../

    # ----------------------------------------------- 
    # 'usbdev_common_cfg_no_src' : common module, do not include sources
    # 'usbdev_cfg_no_hdr'     : all modules, do not include headers. ( defined by parent )
    # -----------------------------------------------
    ! contains ( USBDEV_CFG, usbdev_cfg_hdr_and_src ) {
        USBDEV_CFG *= usbdev_common_cfg_no_src 
                      usbdev_main_cfg_no_src

        contains( USBDEV_CFG, usbdev_cfg_no_hdr ) {
            USBDEV_CFG *= usbdev_common_cfg_no_hdr
                          usbdev_main_cfg_no_hdr
        }
        USBDEV_CFG *= usbdev_cfg_only_lib

    } else {
        # here means include source and header
    }

    # -----------------------------------------------
    # 'usbdev_cfg_only_lib': do not include all modules ( defined by parent )
    # -----------------------------------------------
    ! contains( USBDEV_CFG, usbdev_cfg_only_lib ) {
        include( $$PWD/common/usbdev_common.pri  )
        include( $$PWD/main/usbdev_main.pri )

    } else {
        message( usbdev only contain library )

        USBDEV_MODULE_QT_BUILD  = $$section( QMAKESPEC, /, -3, -3)
        USBDEV_MODULE_QT_VER    = $$section( QMAKESPEC, /, -4, -4)
        USBDEV_MODULE_QT_MMVER  = $$section( USBDEV_MODULE_QT_VER, ., 0, 1 )

        LIBS *= -L"$$PWD/qt$${USBDEV_MODULE_QT_MMVER}/$$USBDEV_MODULE_QT_BUILD"

        CONFIG( debug, debug|release ) {
            LIBS *= -lusbdevd
        } else {
            LIBS *= -lusbdev
        }
    }
}
