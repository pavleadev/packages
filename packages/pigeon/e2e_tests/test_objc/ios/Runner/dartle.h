// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Autogenerated from Pigeon (v0.2.1), do not edit directly.
// See also: https://pub.dev/packages/pigeon
#import <Foundation/Foundation.h>
@protocol FlutterBinaryMessenger;
@class FlutterError;
@class FlutterStandardTypedData;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ACRequestState) {
  ACRequestStatePending = 0,
  ACRequestStateSuccess = 1,
  ACRequestStateFailure = 2,
};

@class ACSearchReply;
@class ACSearchRequest;
@class ACNested;

@interface ACSearchReply : NSObject
@property(nonatomic, copy, nullable) NSString *result;
@property(nonatomic, copy, nullable) NSString *error;
@property(nonatomic, assign) ACRequestState state;
@end

@interface ACSearchRequest : NSObject
@property(nonatomic, copy, nullable) NSString *query;
@property(nonatomic, strong, nullable) NSNumber *anInt;
@property(nonatomic, strong, nullable) NSNumber *aBool;
@end

@interface ACNested : NSObject
@property(nonatomic, strong, nullable) ACSearchRequest *request;
@end

@interface ACFlutterSearchApi : NSObject
- (instancetype)initWithBinaryMessenger:(id<FlutterBinaryMessenger>)binaryMessenger;
- (void)search:(ACSearchRequest *)input
    completion:(void (^)(ACSearchReply *, NSError *_Nullable))completion;
@end
@protocol ACNestedApi
- (nullable ACSearchReply *)search:(ACNested *)input error:(FlutterError *_Nullable *_Nonnull)error;
@end

extern void ACNestedApiSetup(id<FlutterBinaryMessenger> binaryMessenger,
                             id<ACNestedApi> _Nullable api);

@protocol ACApi
- (void)initialize:(FlutterError *_Nullable *_Nonnull)error;
- (nullable ACSearchReply *)search:(ACSearchRequest *)input
                             error:(FlutterError *_Nullable *_Nonnull)error;
@end

extern void ACApiSetup(id<FlutterBinaryMessenger> binaryMessenger, id<ACApi> _Nullable api);

NS_ASSUME_NONNULL_END
