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

Pull requests are more than welcomed!

## License
Usage is provided under the [MIT License](http://http//opensource.org/licenses/mit-license.php). See LICENSE for the full details.

