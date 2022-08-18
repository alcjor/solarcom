package test.java;

import org.junit.Test;

import java.util.HashMap;

public class PeopleTest {

    interface GreetingHandler {
        void greet(Person human);
    }

    public abstract class Person {
        public String name;
        protected HashMap<Class, GreetingHandler> greetingMap;

        protected abstract void initGreetingMap();
        Person(String name) {
            this.name = name;
            this.initGreetingMap();
        }

        public void greet(Person human) {
            GreetingHandler handler = this.greetingMap.get(human.getClass());
            handler.greet(human);
        }

    }

    class FrenchPerson extends Person {
        FrenchPerson(String name) {
            super(name);
        }

        @Override
        protected void initGreetingMap() {
            greetingMap = new HashMap<>();
//            greetingMap.put(GermanPerson.class, (x) -> greetGerman((GermanPerson) x));
            greetingMap.put(FrenchPerson.class, (x) -> greetFrenchie((FrenchPerson) x));
        }

        protected void greetFrenchie (FrenchPerson fellow) {
            System.out.println("Bon jour, " + fellow.name);
        }

//        protected void greetGerman(GermanPerson german) {
//            System.out.println("Alo, german " + german.name);
//        }

    }

    class GermanPerson extends Person {
        GermanPerson(String name) {
            super(name);
        }

        @Override
        protected void initGreetingMap() {
            greetingMap = new HashMap<>();
            greetingMap.put(GermanPerson.class, (x) -> greetGerman((GermanPerson) x));
            greetingMap.put(FrenchPerson.class, (x) -> greetFrenchie((FrenchPerson) x));

        }

        protected void greetGerman(GermanPerson german) {
            System.out.println("Servus, " + german.name);
        }

        protected void greetFrenchie(FrenchPerson frenchie) {
            System.out.println(frenchie.name + ", du ficken frank!");
        }

    }

    @Test
    public void test() {
        Person Hans = new GermanPerson("Hans");
        Person Michael = new GermanPerson("Michael");
        Person Pierre = new FrenchPerson("Pierre");

        Hans.greet(Michael);
        Hans.greet(Pierre);
        Pierre.greet(Michael);
    }





}
