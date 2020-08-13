//
//  KSMediaConnection.h
//  KSWebRTC
//
//  Created by saeipi on 2020/7/11.
//  Copyright © 2020 saeipi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WebRTC/WebRTC.h>
#import "KSMediaCapturer.h"
#import "KSCallState.h"

@interface KSMediaInfo : NSObject

@property (nonatomic, assign) BOOL              isLocal;
@property (nonatomic,assign ) KSAudioStateType  audioStateType;
@property (nonatomic,assign ) KSCallType        callType;
@property (nonatomic,copy   ) NSString          *name;

@end

@class KSMediaConnection;
@protocol KSMediaConnectionDelegate <NSObject>
// 收到远端流处理
//- (void)mediaConnection:(KSMediaConnection *)mediaConnection peerConnection:(RTCPeerConnection *)peerConnection didAddStream:(RTCMediaStream *)stream;
// 收到候选者
- (void)mediaConnection:(KSMediaConnection *)mediaConnection peerConnection:(RTCPeerConnection *)peerConnection didGenerateIceCandidate:(RTCIceCandidate *)candidate;

- (void)mediaConnection:(KSMediaConnection *)mediaConnection peerConnection:(RTCPeerConnection *)peerConnection didAddReceiver:(RTCRtpReceiver *)rtpReceiver streams:(NSArray<RTCMediaStream *> *)mediaStreams;

- (void)mediaConnection:(KSMediaConnection *)mediaConnection didChangeIceConnectionState:(RTCIceConnectionState)newState;

@end

@interface KSMediaConnection : NSObject

@property (nonatomic, weak  ) id<KSMediaConnectionDelegate> delegate;
@property (nonatomic, strong        ) RTCPeerConnection *connection;//WebRTC连接对象
@property (nonatomic, weak          ) KSMediaCapturer   *capturer;
@property (nonatomic, strong        ) RTCVideoTrack     *remoteVideoTrack;//视频轨
@property (nonatomic, weak          ) RTCEAGLVideoView  *remoteVideoView;
@property (nonatomic, strong        ) NSNumber          *handleId;
@property (nonatomic, strong        ) KSMediaInfo       *mediaInfo;
@property (nonatomic,assign         ) int               index;
@property (nonatomic, weak, readonly) AVCaptureSession  *captureSession;
@property (nonatomic, assign        ) BOOL              isClose;

- (RTCPeerConnection *)createPeerConnectionOfKSMediaCapture:(KSMediaCapturer *)capture;
- (void)createOfferWithCompletionHandler:(void (^)(RTCSessionDescription *sdp, NSError *error))completionHandler;
// 创建answer
- (void)createAnswerWithCompletionHandler:(void (^)(RTCSessionDescription *sdp, NSError *error))completionHandler;
- (void)setRemoteDescriptionWithJsep:(NSDictionary *)jsep;
- (void)close;
- (void)muteAudio;
- (void)unmuteAudio;

@end