# PT50 Audio File Management System


### Overview
This program will read through audio files provided by the user and prompt allow them to edit the METADATA of the file or process the file with an effect (Echo, Normalization, or a Noisegate). The program supports mono and stereo .WAV files as well as 8-bit and 16-bit .WAV files. The user is then able to overwrite an existing file's METADATA, or save a new file with the added processing. The user can also create a .CSV file of all the audio files' METADATAs.


### Design Overview
(place finished UML DIAGRAM here)


### The `Processor` Interface
This is an interface with the following function: `processBuffer`


### The `Echo` Template Class
This class is a template with one attribute:

* delay

It has a constuctor:`Echo`

The `processBuffer` function in the Echo class should pass in an audio file and give it an echo of a given delay.
