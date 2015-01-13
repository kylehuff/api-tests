# Simple repo for testing Native Messaging and JSCTYPES api(s)

Native Messaging test -

build the native messaging host (binary)
```
g++ nativehost.cpp -o nativehost
```

Update the file `org.apitest.nativehost` to reflect the actual path to the `nativehost` binary

Place the JSON manifest (`org.apitest.nativehost`) in the appropriate chrome directory

`~/.config/google-chrome/NativeMessagingHosts/` on linux
`~/Library/Google/Crome/NativeMessagingHosts/` on OSX

Windows, TBA -- requires reg key in HKCU...

Load the unpacked app into Chrome via the extensions tab `chrome://extensions`

Start the app.

Any message sent (without the word "echo") will return a (bogus) version string.

Any message with the word "echo" will echo whatever was sent.
