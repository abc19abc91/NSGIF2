Pod::Spec.new do |s|

  # ―――  Spec Metadata  ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  #
  #  These will help people to find your library, and whilst it
  #  can feel like a chore to fill in it's definitely to your advantage. The
  #  summary should be tweet-length, and the description more in depth.
  #

  s.name         = "NSGIF2"
  s.version      = "1.5.1"
  s.summary      = "Create a GIF from the provided video file url."
  s.homepage     = "https://github.com/metasmile/NSGIF2"
  s.screenshots  = "https://raw.githubusercontent.com/metasmile/NSGIF2/master/title.png"


  # ―――  Spec License  ――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  #
  #  Licensing your code is important. See http://choosealicense.com for more info.
  #  CocoaPods will detect a license file if there is a named LICENSE*
  #  Popular ones are 'MIT', 'BSD' and 'Apache License, Version 2.0'.
  #

  s.license      = "MIT (example)"
  s.license      = { :type => "MIT", :file => "LICENSE" }
  s.author       = { "Brian Lee" => "your@elie.camera", "Sebastian Dobrincu (original repo)" => "sebyddd@gmail.com" }
  s.platform     = :ios
  s.ios.deployment_target = '8.0'
  s.source       = { :git => 'https://github.com/metasmile/NSGIF2.git', :tag => "#{s.version}" }
  s.source_files  = "NSGIF/*.{h,m}"

  s.requires_arc = true

end
