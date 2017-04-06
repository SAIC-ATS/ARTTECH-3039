# Faster TSNE embedding, etc.

0.  First, place a copy of `image-net-2012.sqlite3` and `image-net-2012.words`in the `00_BatchFeatureEncoder/bid/data` folder.

1. First use `00_BatchFeatureEncoder` to encode all of your images. This will create a whole bunch of data files that correspond to the features from the given network layer that is specified in the `settings.json`.  You can load them from the `settings.json` file or you should be able to drag and drop files.  The gui should show you how many jobs your workers have remaining.  Data that has already been processed will be skipped if the data file is found, so stopping and starting won't lose your data.

2. Next calculate the reduced dimensionality embeddings using TSNE.  See `01_EmbedFeatures2D`.  This is not fast or parallel.  It is slow.  Sorry.  This will produce a file called "`image_embeddings.json`". That file will feed the next program ...

  - **EDIT** April 5 - I just added a new addon [ofxTSNEParallel](https://github.com/bakercp/ofxTSNEParallel) that can speed up part 2 significantly. Instead of using `ofxTSNE`, replace `ofxTSNE` with `ofxTSNEParallel` in the `01_EmbedFeatures2D/addons.make` file. It requires a little extra setup so see the README for ofxTSNEParallel.

3.  Assign your embeddings to a grid using ofxAssignment. In `02_AssignFeatures2D` you will read from the `image_embeddings.json` created in step two.  Be aware that your `nx` and `ny` values, etc must correspond to the number of images or else you'll get crashes or empty grids.

_Why all of this?_

The main thing illustrated here is the parallelization of step 1.  Multiple threads process each image.  The second important part is the "serialization" of intermediate data (usually as json -- but also as raw binary data in the case of 1.). so that we don't lose our progress when processing big jobs.

You might play around with using different layers, different "perplexities", etc.

Also note that all of the data has already been calculated for this example.  Thus it may not seem like it did anything.  Please check the output messages on the console.

To use it on your data, either point the `00_BatchFeatureEncoder` settings file to your data, and adjust all three other settings files, OR place all of your images in the `00_BatchFeatureEncoder/bid/data/images` folder and run all three programs in sequence.
