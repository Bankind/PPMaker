//
//  PPMaker.h
//  PPDemo
//
//  Created by ╰莪呮想好好宠Nǐつ on 2018/5/7.
//  Copyright © 2018年 PPAbner. All rights reserved.
//

#ifndef PPMaker_h
#define PPMaker_h

//【warning】 注意引入头文件是 #import "PPMaker.h",而不是#import "PPMake.h"
//【warning】 注意引入头文件是 #import "PPMaker.h",而不是#import "PPMake.h"
//【warning】 注意引入头文件是 #import "PPMaker.h",而不是#import "PPMake.h"

//UIKit
#import "PPMake.h"
#import "PPMake+UILabel.h"
#import "PPMake+UITableView.h"
#import "PPMake+UIButton.h"
#import "PPMake+UIImageView.h"

//Foundation
#if __has_include(<PPMaker/PPMutAttributedStringMaker.h>)
#import <PPMaker/PPMutAttributedStringMaker.h>
#endif

#import "PPMakerConsts.h"

NS_ASSUME_NONNULL_BEGIN

CG_INLINE BOOL isSafeStr(NSString * _Nullable str){
    if ([str isKindOfClass:[NSNull class]]
        || str == nil
        || str.length == 0
        || [str isEqualToString:@"(null)"]
        || [str isEqualToString:@"null"]
        || [str isEqualToString:@"NULL"]
        || [str isEqualToString:@"（null）"]
        || [str isEqualToString:@"<null>"]
        || [str isEqualToString:@"<NULL>"]
        || [str isEqualToString:@"nil"]){
        return NO;
    }else{
        return YES;
    }
}

CG_INLINE NSString *safeStr(NSString * _Nullable str){
    if (isSafeStr(str)) {
        return str;
    }
    return @"";
}


/**
 用字符串b替换字符串str中的a
 
 @param str 原始字符串
 @param a 字符串a
 @param b 字符串b
 @return b替换a后新的字符串
 */
CG_INLINE NSString *replaceAWithB(NSString *str,NSString *a,NSString *b){
    if (![str containsString:a]) {
        return str;
    }
    NSRange totalRange = NSMakeRange(0, str.length);
    NSString *newStr = [str stringByReplacingOccurrencesOfString:a withString:b options:NSLiteralSearch range:totalRange];
    return newStr;
}

/** 移除字符串str中的所有空格 */
CG_INLINE NSString *removeSpace(NSString *str){
    return replaceAWithB(str, @" ", @"");
}

#pragma mark --- 正则表达式相关的NSString ----- start
CG_INLINE BOOL isMatchedUsingRegex(NSString *str,NSString *limitTypeKey){
    if (!isSafeStr(str)) {
        return NO;
    }
    NSPredicate *predicate = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", limitTypeKey];
    BOOL isMatch = [predicate evaluateWithObject:str];
    return isMatch;
}

CG_INLINE BOOL isMatchedUsingPPMakerRegex(NSString *str,PPMakerRegularExpressionLimitTypeKey limitTypeKey){
    return isMatchedUsingRegex(str, limitTypeKey);
}
#pragma mark --- 正则表达式相关的NSString ----- end

CG_INLINE BOOL isNumber(NSString *str){
    return isMatchedUsingPPMakerRegex(str, PPMakerRegularExpressionLimitTypeKeyNumber);
}



NS_ASSUME_NONNULL_END

#endif /* PPMaker_h */
