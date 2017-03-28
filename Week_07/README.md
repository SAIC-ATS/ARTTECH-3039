# Faster TSNE embedding, etc.

1. First use `00_BatchFeatureEncoder` to encode all of your images. This will create a whole bunch of data files that correspond to the features from the given network layer that is specified in the `settings.json`.  You can load them from the `settings.json` file or you should be able to drag and drop files.  The gui should show you how many jobs your workers have remaining.  Data that has already been processed will be skipped if the data file is found, so stopping and starting won't lose your data.

2. Next calculate the reduced dimensionality embeddings using TSNE.  See `01_EmbedFeatures2D`.  This is not fast or parallel.  It is slow.  Sorry.  This will produce a file called "`image_embeddings.json`". That file will feed the next program ...

3.  Assign your embeddings to a grid using ofxAssignment. In `02_AssignFeatures2D` you will read from the `image_embeddings.json` created in step two.  Be aware that your `nx` and `ny` values, etc must correspond to the number of images or else you'll get crashes or empty grids.

_Why all of this?_

The main thing illustrated here is the parallelization of step 1.  Multiple threads process each image.  The second important part is the "serialization" of intermediate data (usually as json -- but also as raw binary data in the case of 1.). so that we don't lose our progress when processing big jobs.

You might play around with using different layers, different "perplexities", etc.

Also note that all of the data has already been calculated for this example.  Thus it may not seem like it did anything.  Please check the output messages on the console.

