# SOLARCOM
*An Object-Oriented Code for the Simulation of Deep Space Communication Networks*

Authors: Paula Betriu, Jordi Alcón, Manel Soria, Jordi Gutiérrez, Sergi Berdor, and Carles Farré
---

## Installation

> In order to use this software, you must have the SPICE toolkit for JNI installed in your system. 
> Refer to the [official documentations](https://naif.jpl.nasa.gov/naif/toolkit.html) for details. 

To install Solarcom in your system, download the JAR file from the Releases section.
Put it in a directory of your choice. Then, in that directory, create a new file named `config.yaml`.
In that file, you should create three entries, which indicate the path to the SPICE installation folder,
the path to the folder where you'll store your SPICE kernels, and the path to the folder where extensions of
the code will be placed.

```yaml
spicePath: "/home/username/SPICE/JNISpice/lib"
kernelPath: "/home/username/SpiceKernels" # Change the paths according to your installation
classPath: "/home/username/SolarcomExtensions"
```

Once you've created the config file, Solarcom will be ready for execution.

## Running a Simulation

Download the examples' folder from the repository. Open one of the examples. There, you'll find a single
Yaml file. This is the *Simulation File*, which defines the network and contains the data necessary for
Solarcom to perform a simulation. To run the simulation, execute the following command:


```shell

~/path/to/example$ java -jar $SOLARCOM_JAR exampleFile.yaml

```

The simulation should start running now. Once it's finished, three new CSV files should appear in the directory.
The first one, named as the simulation file, contains the maximum data rate for both the consecutive and the
simultaneous models of communication at every instant, along with the corresponding routes.
The second, `nodes.csv`, will contain information about the nodes of the network. And the third,
`links.csv`, will contain the data rate of every link at every instant of time.


[//]: # (## Making a Simulation file)

[//]: # ()
[//]: # (Take a look at the simulation file you've just run. You can customiz)


[//]: # (## Extending the code)

[//]: # ()
[//]: # (Coming soon...)
