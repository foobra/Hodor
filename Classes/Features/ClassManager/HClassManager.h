//
//  HClassManager.h
//  HFramework
//
//  Created by 火辣先生 on 12-12-21.
//  Copyright (c) 2012年 iTotemStudio. All rights reserved.
//

#import <Foundation/Foundation.h>

//class register : regiester some class on key
#define HReg(key) \
+ (void)load\
{\
    [super load];\
    [HClassManager registerClass:self forkey:key];\
}
//class register : register some class on key with userinfo
#define HReg2(key,userinfo) \
+ (void)load\
{\
[super load];\
[HClassManager registerClass:self forkey:key userInfo:userinfo];\
}


typedef BOOL (^HClassScanBlock)(Class aclass);
typedef void (^HClassFetchBlock)(Class aclass, id userInfo);
typedef void (^HClassNameFetchBlock)(NSString *aclassName, id userInfo);


/**
 *  class register manager
 *
 *  this feature could be use on some deconfig solution
 *  if you register self in +load function for some key, then ,some other module could use the key to find the class
 *  we always use the feature to find implementers of a protocal or subclass of a base class
 *
 */
@interface HClassManager : NSObject
+ (void)registerClass:(Class)aclass forkey:(NSString *)key;
+ (void)registerClass:(Class)aclass forkey:(NSString *)key userInfo:(id)userInfo;
+ (void)scanClassForKey:(NSString *)key fetchblock:(HClassFetchBlock)block;
+ (void)scanClassNameForKey:(NSString *)key fetchblock:(HClassNameFetchBlock)block;
//return the first one that found
+ (NSString *)getClassNameForKey:(NSString *)key;
//delete the key and class info
+ (void)removeClassForKey:(NSString *)key;
@end


/**
 *  Class info container， you need not care about it
 */
@interface HClassContainner : NSObject
@property (nonatomic, strong) NSString *containClassName;
@property (nonatomic, strong) id userInfo;
@property (nonatomic, strong) id H_Reg;
@end
