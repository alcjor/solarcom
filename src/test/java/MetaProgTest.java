package test.java;

import org.junit.Test;
import space.KernelBody;
import spice.basic.SpiceException;

import java.lang.reflect.Constructor;
import java.lang.reflect.InvocationTargetException;

public class MetaProgTest {

    @Test
    public void simpleTest() {
        Class myClass = null;
        try {
            myClass = Class.forName("test.java.MyClass");
//            Class[] types = {Double.TYPE};
            Class[] types = {};
            Constructor constructor = myClass.getConstructor(types);

//            Object[] parameters = {new Double(0)};
            Object[] parameters = {};
            Object instanceOfMyClass = constructor.newInstance(parameters);


            Class kb = Class.forName("links.RadioLink");
            Constructor[] constructor1 = kb.getConstructors();
            System.out.println(constructor1[0].getParameterTypes().length);
            for (Class c: constructor1[0].getParameterTypes()) {
                System.out.println(c.toString());
            }


        } catch (Exception e) {
            throw new RuntimeException(e);
        }


    }


}
