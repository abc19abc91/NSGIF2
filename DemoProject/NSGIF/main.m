//
//  main.m
//  NSGIF
//
//  Created by Metasmile on 30/08/15.
//  Copyright (c) 2015 Sebastian Dobrincu. All rights reserved.
//
#import <UIKit/UIKit.h>
#import "AppDelegate.h"

#if DEBUG
void uncaughtExceptionHandler(NSException *exception) {
    NSLog(@"Exception: %@", exception);
    NSLog(@"Stack Trace: %@", [exception callStackSymbols]);
}
#endif

int main(int argc, char * argv[]) {
    @autoreleasepool {
#if DEBUG
        NSSetUncaughtExceptionHandler(&uncaughtExceptionHandler);
#endif
        return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class]));
    }
}
