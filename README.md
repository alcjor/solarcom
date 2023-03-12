# SOLARCOM
*An Object-Oriented Code for the Simulation of Deep Space Communication Networks*



Paula Betriu, Jordi Alcón, Manel Soria, Jordi Gutiérrez, Sergi Berdor, and Carles Farré

---

## Installation

> In order to use this software, you must have the SPICE toolkit for JNI installed in your system. 
> Refer to the [official documentations](https://naif.jpl.nasa.gov/naif/toolkit.html) for details. 

To install Solarcom in your system, download the JAR file from the Releases section.
Put it in a directory of your choice (e.g. `/home/username/solarcom`). Then, in that directory, create a new file named `config.yaml`.
In that file, you should create three entries, which indicate the path to the SPICE installation folder,
the path to the folder where you'll store your SPICE kernels, and the path to the folder where extensions of
the code will be placed.

```yaml
spicePath: "/home/username/SPICE/JNISpice/lib"
kernelPath: "/home/username/SpiceKernels" # Change the paths according to your installation
classPath: "/home/username/solarcom"
```

Once you've created the config file, Solarcom will be ready for execution. Your directory structure should look as follows:


## Running a Simulation

Open one of the examples. There, you'll find a single
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



## Extending the code

Extensions of the code must be placed in the directory specified in `config.yaml`. Create a new package for extensions there.
If you followed the example above, your directory should look as follows:

```shell
- /home/username/solarcom/
    - config.yaml
    - solarcom.jar
    - /extension1/
      - class1.java
      ...
      - classN.java
    - /extension2/
      - class1.java
      ...
      - classN.java 
    ... 
```

Once you've implemented the extensions, compile them as follows:

```shell

~/path/to/example$ javac -cp $SOLARCOM_JAR extendingClass.java

```

Now, you can execute the code with the extension. Create a new simulation file and add the desired instances 
of the class as if it was a built-in class, but preceded with the package name:

```yaml

- extension1.class1:
    - instanceName:
        - attr1: value
        - attr2: value
        ...
```
The order of the attributes must match that of the constructor.