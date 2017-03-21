# YOLO BATCH

- Move to the place where you want to install `cd SOMEWHERE`
- `git clone -b batch_to_json https://github.com/bakercp/darknet.git`
- `cd darknet`
- `make -j8 -s` Make the darknet executable.
- `./detector.sh` To download the net weights initial (you will get an ambigious error.)
- To run a single directory ...
  - `./darknet detector batch_test cfg/coco.data cfg/yolo.cfg yolo.weights data/` Don't forget the trailing slash/
- To run on a list of directories ...

- Make a file called `folders.txt` in your `darknet` directory.
- An example `folders.txt` file _might_ look like this (make sure there is a trailing slash /.

```
/PATH/TO/MY/FOLDER/FULL/OF/IMAGES/
/PATH/TO/MY/FOLDER/FULL/OF/OTHER/IMAGES/
```

- To process all images in all listed folders run
  -  `./detector.sh folders.txt`

