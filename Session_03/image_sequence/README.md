# Example Description

This example creates images sequences that can be turned into videos with Quicktime or ffmpeg with a command like:

```
ffmpeg -i FRAME_%04d.png -vcodec libx264 -vf format=yuv420p movie.mp4
```

An example video can be downloaded [here](http://christopherbaker.net/dropbox/hands.mp4).