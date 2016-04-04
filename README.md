![NSGIF](https://dl.dropboxusercontent.com/s/0rq3fr0dtpvwd4h/NSGIF-header.png?dl=0)

This generates a GIF from the provided video file url.

*Please refer this repo has been separated for some improvements. Please do diff each other, and visit [original repo](https://github.com/NSRare/NSGIF) for more information if you need.*

## Installation

There are 2 ways you can add NSGIF to your project:

### Manual

Simply import the 'NSGIF' into your project then import the following in the class you want to use it: 
```objective-c
#import "NSGIF.h"
```      
### From CocoaPods

```ruby
platform :ios, '7.0'
pod "NSGIF", "~> 1.0"
```

## Usage

```objective-c
//default request automatically set the best frame count, delay time or size. see interface file for more options.
NSGIFRequest * request = [NSGIFRequest requestWithSourceVideo:tempFileURL destination:gifFileURL];
request.progressHandler = ^(double progress, NSUInteger position, NSUInteger length, CMTime time, BOOL *stop, NSDictionary *frameProperties) {
    NSLog(@"%f - %d - %d - %d - %@",progress, position, length, time.value, frameProperties);
};

[NSGIF create:request completion:^(NSURL *GifURL) {
    //GifURL is to nil if it failed.
}];
```

## Options
```objective-c
@interface NSGIFRequest : NSObject

/* required. a file's url of source video */
@property(nullable, nonatomic) NSURL * sourceVideoFile;
/* optional. defaults to nil. automatically assign the file name of source video (ex: IMG_0000.MOV -> IMG_0000.gif)  */
@property(nullable, nonatomic) NSURL * destinationVideoFile;
/* optional. Defaults to NSGIFScaleOptimize (not set). */
@property(nonatomic, assign) NSGIFScale scalePreset;
/* optional. Defaults to 4. number of frames in seconds */
@property(nonatomic, assign) NSUInteger framesPerSecond;
/* optional. Defaults is to not set. How far along the video track we want to move, in seconds. It will automatically assign from duration of video and framesPerSecond  */
@property(nonatomic, assign) NSUInteger frameCount;
/* optional. Defaults to 0, the number of times the GIF will repeat. which means repeat infinitely. */
@property(nonatomic, assign) NSUInteger loopCount;
/* optional. Defaults to 0.13. unit is 10ms, 1/100s, the amount of time for each frame in the GIF */
@property(nonatomic, assign) CGFloat delayTime;
/* optional. Defaults is to not set. unit is seconds, which means unlimited */
@property(nonatomic, assign) NSTimeInterval maxDuration;
/* optional. Defaults is nil */
@property (nonatomic, copy, nullable) NSGIFProgressHandler progressHandler;

- (NSGIFRequest * __nonnull)initWithSourceVideo:(NSURL * __nullable)fileURL;
+ (NSGIFRequest * __nonnull)requestWithSourceVideo:(NSURL * __nullable)fileURL;
+ (NSGIFRequest * __nonnull)requestWithSourceVideo:(NSURL * __nullable)fileURL destination:(NSURL * __nullable)videoFileURL;
+ (NSGIFRequest * __nonnull)requestWithSourceVideoForLivePhoto:(NSURL *__nullable)fileURL;
@end
```

Pull requests are more than welcomed!

## License
Usage is provided under the [MIT License](http://http//opensource.org/licenses/mit-license.php). See LICENSE for the full details.

