# YOLO BATCH

- Move to the place where you want to install `cd SOMEWHERE`
- `git clone -b batch_to_json https://github.com/bakercp/darknet.git`
- `cd darknet` **ALL SUBSEQUENT COMMANDS SHOULD BE RUN FROM THIS FOLDER**
- `make -j8 -s` Make the darknet executable.
- `./detector.sh` To download the net weights initial (you will get an ambigious error.)
- To run a single directory ...
  - `./darknet detector batch_test cfg/coco.data cfg/yolo.cfg yolo.weights data/` Don't forget the trailing slash/
- To run on a list of directories ...

- Make a plain text file called `folders.txt` in your `darknet` directory using your favorite text editor (`atom`, `vi`, `nano`, `sublime`, `text wrangler`).
- An example `folders.txt` file _might_ look like this (make sure there is a trailing slash /.

**THERE MUST BE AN EMPTY LINE AT THE END OF THE** `folders.txt`

```
/PATH/TO/MY/FOLDER/FULL/OF/IMAGES/
/PATH/TO/MY/FOLDER/FULL/OF/OTHER/IMAGES/

```

- To process all images in all listed folders run
  -  `./detector.sh folders.txt`
