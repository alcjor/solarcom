package space;

import java.util.Arrays;

public class ClassTuple {
    public static ClassTuple of(Class ... values)
    {
        return new ClassTuple(values);
    }

    private final Class data[];
    private ClassTuple(Class ... data)
    {
        this.data = data;
    }

    public int getDimensions()
    {
        return data.length;
    }

    public Class get(int index)
    {
        return data[index];
    }
    @Override
    public String toString()
    {
        return Arrays.toString(data);
    }
    @Override
    public int hashCode()
    {
        return Arrays.hashCode(data);
    }
    @Override
    public boolean equals(Object object)
    {
        if (this == object)
        {
            return true;
        }
        if (object == null)
        {
            return false;
        }
        if (!(object instanceof ClassTuple))
        {
            return false;
        }
        ClassTuple other = (ClassTuple) object;
        return Arrays.equals(data, other.data);
    }
}
