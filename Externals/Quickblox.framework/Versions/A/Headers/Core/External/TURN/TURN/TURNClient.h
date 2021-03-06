//
//  TURNClient.h
//  TURN
//
//  Created by Igor Khomenko on 9/19/12.
//  Copyright (c) 2012 Quickblox. All rights reserved. Check our BAAS quickblox.com
//
//
// This a simple and ad-hoc TURN client (UDP), partially compliant with RFC 5766
//
// Documentation http://www.jdrosen.net/papers/draft-rosenberg-midcom-turn-02.html & http://tools.ietf.org/html/rfc5766
//
// From quickblox.com team with love!
//


#import <Foundation/Foundation.h>
#import "GCDAsyncUdpSocket.h"
#import "GCDAsyncSocket.h"

// TURN default port
#define TURNPort 3478

// TURN server. See http://en.wikipedia.org/wiki/Traversal_Using_Relays_around_NAT for setup your own or use free. 

#define TURNServer @"turn2.quickblox.com"

#define allocatedIPKey @"allocatedIPKey"
#define allocatedPortKey @"allocatedPortKey"
#define publicXORAddressKey @"publicXORAddressKey"
//
#define publicNatIPKey @"publicNatIPKey"
#define publicNatPortKey @"publicNatPortKey"

// Enable/disable auth (some TURN servers use auth, in some we can disable it)
#define authEnable YES

// Enable/disable log
#define log 1
#define TURNLog(...) if (log) NSLog(__VA_ARGS__)

@protocol TURNClientDelegate;
@interface TURNClient : NSObject <GCDAsyncUdpSocketDelegate, GCDAsyncSocketDelegate>{
    NSData *magicCookie;
    
    NSData *NONCE;
    NSData *REALM;
    NSData *USERNAME;
    NSData *MESSAGE_INTEGRITY;
}
@property (nonatomic, retain) GCDAsyncUdpSocket *udpSocket;
@property (nonatomic, retain) GCDAsyncSocket *tcpSocket;
@property (nonatomic, assign) id<TURNClientDelegate>delegate;

// TURN
//
// over UDP
- (void)sendAllocationRequest;
- (void)sendPermissionRequestWithPeer:(NSData *)peer;
- (void)sendRefreshRequest;
//
// over TCP
- (void)sendAllocationRequestTCP;
- (void)sendConnectRequestTCPWithPeer:(NSData *)peer;
- (void)sendRefreshRequestTCP;

// STUN
//
// over UDP
- (void)sendBindingRequest;
- (void)sendIndicationMessage;
//
// over TCP
- (void)sendBindingRequestTCP;
- (void)sendIndicationMessageTCP;

@end


// Turn response type
enum TURNResponseType{
	TURNResponseTypeBinding,
	TURNResponseTypeAllocation,
	TURNResponseTypeData,
    TURNResponseTypePermisison,
    TURNResponseTypeRefresh,
    TURNResponseTypeIndication,
    TURNResponseTypeUndefined
};


// TURN delegate
@protocol TURNClientDelegate <NSObject>
@optional
- (void)didReceiveAllocationResponse:(NSDictionary *) data;
- (void)didReceiveBindingResponse:(NSDictionary *) data;
- (void)didReceivePermissionResponse;
- (void)didReceiveData:(NSData *) data;
- (void)didFailWithError:(NSString *) error code:(int)errorCode;
- (void)didConnectToTURNServerUsingTCP;
@end