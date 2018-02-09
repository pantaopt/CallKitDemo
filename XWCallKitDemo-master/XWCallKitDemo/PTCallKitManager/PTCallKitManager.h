#import <Foundation/Foundation.h>
#import <CallKit/CallKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ADCallActionType) {
    ADCallActionTypeStart,
    ADCallActionTypeEnd,
    ADCallActionTypeAnswer,
    ADCallActionTypeMute,
    ADCallActionTypeHeld
};

typedef NS_ENUM(NSInteger, ADCallState) {
    ADCallStatePending,
    ADCallStateConnecting,
    ADCallStateConnected,
    ADCallStateEnded,
    ADCallStateEndedWithFailure,
    ADCallStateEndedUnanswered
};

typedef void(^PTCallKitManagerCompletion)(NSError * _Nullable error);
typedef void(^ADCallKitActionNotificationBlock)(CXCallAction * action, ADCallActionType actionType);

@protocol ADContactProtocol <NSObject>

- (NSString *)displayName;
- (NSString *)phoneNumber;

@end

@class ADUser;
@interface PTCallKitManager : NSObject

@property (nonatomic, strong) dispatch_queue_t completionQueue; // Default to mainQueue

+ (PTCallKitManager *)sharedInstance;
- (void)setupWithAppName:(NSString *)appName supportsVideo:(BOOL)supportsVideo actionNotificationBlock:(ADCallKitActionNotificationBlock)actionNotificationBlock;

- (NSUUID *)reportIncomingCallWithContact:(id<ADContactProtocol>)contact completion:(PTCallKitManagerCompletion)completion;
- (NSUUID *)reportOutgoingCallWithContact:(id<ADContactProtocol>)contact completion:(PTCallKitManagerCompletion)completion;
- (void)updateCall:(NSUUID *)callUUID state:(ADCallState)state;

- (void)mute:(BOOL)mute callUUID:(NSUUID *)callUUID completion:(PTCallKitManagerCompletion)completion;
- (void)hold:(BOOL)hold callUUID:(NSUUID *)callUUID completion:(PTCallKitManagerCompletion)completion;
- (void)endCall:(NSUUID *)callUUID completion:(PTCallKitManagerCompletion)completion;

@end
NS_ASSUME_NONNULL_END
