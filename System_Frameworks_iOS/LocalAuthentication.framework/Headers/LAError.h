//
//  LAError.h
//  LocalAuthentication
//
//  Copyright (c) 2013 Apple. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <LocalAuthentication/LAPublicDefines.h>

typedef NS_ENUM(NSInteger, LAError)
{
    /// Authentication was not successful, because user failed to provide valid credentials.
    LAErrorAuthenticationFailed = kLAErrorAuthenticationFailed,
    
    /// Authentication was canceled by user (e.g. tapped Cancel button).
    LAErrorUserCancel = kLAErrorUserCancel,
    
    /// Authentication was canceled, because the user tapped the fallback button (Enter Password).
    LAErrorUserFallback = kLAErrorUserFallback,
    
    /// Authentication was canceled by system (e.g. another application went to foreground).
    LAErrorSystemCancel = kLAErrorSystemCancel,
    
    /// Authentication could not start, because passcode is not set on the device.
    LAErrorPasscodeNotSet = kLAErrorPasscodeNotSet,

    /// Authentication could not start, because Touch ID is not available on the device.
    LAErrorTouchIDNotAvailable NS_ENUM_DEPRECATED(10_10, 10_13, 8_0, 11_0, "use LAErrorBiometryNotAvailable") = kLAErrorTouchIDNotAvailable,

    /// Authentication could not start, because Touch ID has no enrolled fingers.
    LAErrorTouchIDNotEnrolled NS_ENUM_DEPRECATED(10_10, 10_13, 8_0, 11_0, "use LAErrorBiometryNotEnrolled") = kLAErrorTouchIDNotEnrolled,

    /// Authentication was not successful, because there were too many failed Touch ID attempts and
    /// Touch ID is now locked. Passcode is required to unlock Touch ID, e.g. evaluating
    /// LAPolicyDeviceOwnerAuthenticationWithBiometrics will ask for passcode as a prerequisite.
    LAErrorTouchIDLockout NS_ENUM_DEPRECATED(10_11, 10_13, 9_0, 11_0, "use LAErrorBiometryLockout")
        __WATCHOS_DEPRECATED(3.0, 4.0, "use LAErrorBiometryLockout") __TVOS_DEPRECATED(10.0, 11.0, "use LAErrorBiometryLockout") = kLAErrorTouchIDLockout,

    /// Authentication was canceled by application (e.g. invalidate was called while
    /// authentication was in progress).
    LAErrorAppCancel NS_ENUM_AVAILABLE(10_11, 9_0) = kLAErrorAppCancel,

    /// LAContext passed to this call has been previously invalidated.
    LAErrorInvalidContext NS_ENUM_AVAILABLE(10_11, 9_0) = kLAErrorInvalidContext,

    /// Authentication could not start, because biometry is not available on the device.
    LAErrorBiometryNotAvailable NS_ENUM_AVAILABLE(10_13, 11_0) __WATCHOS_AVAILABLE(4.0) __TVOS_AVAILABLE(11.0) = kLAErrorBiometryNotAvailable,

    /// Authentication could not start, because biometry has no enrolled identities.
    LAErrorBiometryNotEnrolled NS_ENUM_AVAILABLE(10_13, 11_0) __WATCHOS_AVAILABLE(4.0) __TVOS_AVAILABLE(11.0) = kLAErrorBiometryNotEnrolled,

    /// Authentication was not successful, because there were too many failed biometry attempts and
    /// biometry is now locked. Passcode is required to unlock biometry, e.g. evaluating
    /// LAPolicyDeviceOwnerAuthenticationWithBiometrics will ask for passcode as a prerequisite.
    LAErrorBiometryLockout NS_ENUM_AVAILABLE(10_13, 11_0) __WATCHOS_AVAILABLE(4.0) __TVOS_AVAILABLE(11.0) = kLAErrorBiometryLockout,
    
    /// Authentication failed, because it would require showing UI which has been forbidden
    /// by using interactionNotAllowed property.
    LAErrorNotInteractive API_AVAILABLE(macos(10.10), ios(8.0), watchos(3.0), tvos(10.0)) = kLAErrorNotInteractive,
} NS_ENUM_AVAILABLE(10_10, 8_0) __WATCHOS_AVAILABLE(3.0) __TVOS_AVAILABLE(10.0);

/// LocalAuthentication error domain.
extern NSString *const __nonnull LAErrorDomain
NS_AVAILABLE(10_11, 8_3) __WATCHOS_AVAILABLE(3.0) __TVOS_AVAILABLE(10.0);
