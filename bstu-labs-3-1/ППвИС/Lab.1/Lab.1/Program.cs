using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace lab_1
{
    class INT
    {
        // attributes
        private int val;

        // properties
        public int Value
        {
            get { return val; }
            set { val = value; }
        }

        // constructors
        public INT(int value = 0)
        {
            val = value;
        }

        //  methods
        public static implicit operator int(INT obj)
        {
            return obj.Value;
        }
        public static implicit operator INT(int obj)
        {
            return new INT(obj);
        }
        public static INT operator +(INT left, INT right)
        {
            return left.Value + right.Value;
        }
        public static INT operator ++(INT obj)
        {
            obj.val++;
            return obj;
        }
        public static INT operator -(INT obj)
        {
            return -obj.Value;
        }
        public static bool operator >(INT left, INT right)
        {
            return left.Value > right.Value;
        }
        public static bool operator <(INT left, INT right)
        {
            return left.Value < right.Value;
        }
        override public string ToString()
        {
            return val.ToString();
        }
        public static void Test()
        {
            Console.WriteLine("\nTest INT\n");
            INT i = new INT();
            i = 5; // value assignment
            int x = i; // to int convertion
            Console.WriteLine(string.Format(
                "INT: {0}\nint: {1}",
                i,    // INT
                x           // int
            ));
            Console.WriteLine(string.Format(
                "I++ + 5: {0}",
                i++ + 5    // (5++ + 5)
            ));
            Console.WriteLine(string.Format(
                "I: {0}\n-I: {1}",
                i,
                -i
            ));
            Console.WriteLine(string.Format(
                "5 < 6: {0}",
                new INT(5) < new INT(6)
            ));
            Console.ReadKey();
        }
    }

    class TWO_INT : INT
    {
        private int val_2;
        public TWO_INT() : base() { }
        public TWO_INT(int value_1, int value_2)
            : base(value_1)
        {
            Value_2 = value_2;
        }
        public int Value_2
        {
            get
            {
                return val_2;
            }
            set
            {
                val_2 = value;
            }
        }
        public override string ToString()
        {
            return "(" + Value.ToString() + ", " + Value_2.ToString() + ")";
        }
        public static new void Test()
        {
            Console.WriteLine("\nTest TWO_INT\n");
            TWO_INT ti = new TWO_INT(10, 20);
            Console.WriteLine("Value #1: {0}\nValue #2: {1}",
                ti.Value,
                ti.Value_2
            );
            Console.ReadKey();
        }
    }

    class STRING
    {
        // attributes
        private string str;
        private int length;

        // properties
        public string prStr
        {
            get
            {
                return str;
            }
            set
            {
                str = value;
                length = str.Length;
            }
        }
        public int prLength
        {
            get
            {
                return length;
            }
            private set
            {
                length = value;
            }
        }

        // constructors
        public STRING() : base() { }
        public STRING(STRING obj)
        {
            prStr = obj.prStr;
        }
        public STRING(string str)
        {
            prStr = str;
        }

        //  methods
        public static void Test()
        {
            Console.WriteLine("\nTest STRING\n");
            STRING str = new STRING("message");
            Console.WriteLine("String: {0}", str.prStr);
            Console.ReadKey();
        }
    }

    class ARRAY<T>
    {
        // attributes
        private T[] array;

        // properties
        public T this[int i]
        {
            get
            {
                return array[i];
            }
            set
            {
                if (i < 0)
                    throw new IndexOutOfRangeException();
                else if (i >= array.Length)
                {
                    T[] arr = new T[i + 1];
                    Array.Copy(array, arr, array.Length);
                    arr[i] = value;
                    array = new T[arr.Length];
                    Array.Copy(arr, array, arr.Length);
                }
                array[i] = value;
            }
        }

        // constructors
        public ARRAY() : base()
        {
            array = new T[0];
        }
        public ARRAY(ARRAY<T> obj)
        {
            Array.Copy(obj.array, array, obj.array.Length);
        }
        public ARRAY(T[] arr)
        {
            array = arr;
        }


        // methods
        public static void Test()
        {
            Console.WriteLine("\nTest ARRAY\n");
            ARRAY<int> arr = new ARRAY<int>();
            arr[5] = 10;
            Console.WriteLine("5th element of the array: {0}", arr[5]);
            Console.ReadKey();
        }

    }

    class Container<T>
    {
        // attributes
        private T val;

        // properties
        public T Value
        {
            get { return val; }
            set { val = value; }
        }
        public Container() : base() { }
        public Container(T value)
        {
            val = value;
        }
    }

    interface IMutable<T>
    {
        void TO_SET(T value);
    }
    interface IPrintable
    {
        void TO_SHOW();
    }

    class INT_2 : Container<int>, IMutable<int>, IPrintable
    {
        public INT_2(int value = 2) : base(value) { }

        public void TO_SET(int value)
        {
            Value = value;
        }
        public void TO_SHOW()
        {
            Console.WriteLine("Value: {0}", Value);
        }
        public static void Test()
        {
            Console.WriteLine("\nTest INT_2\n");
            INT_2 i = new INT_2();
            i.TO_SET(10);
            i.TO_SHOW();
            Console.ReadKey();
        }

    }

    class STRING_2 : Container<string>, IMutable<string>, IPrintable
    {
        public STRING_2(string value = "") : base(value) { }

        public void TO_SET(string value)
        {
            Value = value;
        }
        public void TO_SHOW()
        {
            Console.WriteLine("Value: {0}", Value);
        }
        public static void Test()
        {
            Console.WriteLine("\nTest STRING_2\n");
            STRING_2 i = new STRING_2();
            i.TO_SET("hello");
            i.TO_SHOW();
            Console.ReadKey();
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            INT.Test();
            STRING.Test();
            ARRAY<int>.Test();
            TWO_INT.Test();
            INT_2.Test();
            STRING_2.Test();
        }
    }
}
