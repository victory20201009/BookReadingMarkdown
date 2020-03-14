using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyFirstCSharp
{

    public sealed class SingleTon1 {
        private SingleTon1() {
            Console.WriteLine("SingleTon1 init");
        }

        private static SingleTon1 instance = null;

        public static SingleTon1 Instance {
            get {//缺点 线程不安全
                if (instance == null)
                {
                    instance = new SingleTon1();
                }
                return instance;
            }
        }
    }

    public sealed class SingleTon2 {
        private SingleTon2() {
            Console.WriteLine("SingleTon2 init");
        }

        private static SingleTon2 instance = null;

        private static readonly object obj = new object();

        public static SingleTon2 Instance {
            get {
                lock (obj) {//加锁保证线程安全，缺点，每次都要获取锁是不必要的，效率不高
                    if (instance == null)
                    {
                        instance = new SingleTon2();
                    }
                    return instance;
                }
            }
        }
    }

    public sealed class SingleTon3 {

        private SingleTon3() {
            Console.WriteLine("SingleTon3 init");
        }

        private static SingleTon3 instance = null;

        private static readonly object obj = new object();

        public static SingleTon3 Instance {
            get {
                if (instance == null) {//再加一个判断，减少获取锁的次数，提高效率，缺点：代码逻辑复杂
                    lock (obj) {
                        if (instance == null)
                        {
                            instance = new SingleTon3();
                        }
                    }
                }
                return instance;
            }
        }

    }

    public sealed class SingleTon4
    {
        private SingleTon4() {
            Console.WriteLine("SingleTon4 init");
        }

        private static SingleTon4 instance = new SingleTon4();//利用静态构造函数构造静态变量，并且只会调用一次静态构造函数

        public static SingleTon4 Instance {
            get {//代码简洁 缺点：当我们的SingleTon4类中含有其他的工具方法，我们调用这些方法时不需要使用实例对象，但是此时，对象仍然会创建，单例实例不能够按需创建，导致内存使用效率不高
                return instance;
            }
        }

    }

    public sealed class SingleTon5 {

        static SingleTon5() {
            Console.WriteLine("SingleTon5 static init");
        }

        private SingleTon5() {
            Console.WriteLine("SingleTon5 init");
        }

        public static SingleTon5 Instance {

            get {//只有调用这个函数时才会创建对象，达到了按需创建的目的
                return Nested.instance;
            }
        }

        class Nested {
            static Nested() {
                Console.WriteLine("SingleTon5.Nested static init");
            }
            internal static readonly SingleTon5 instance = new SingleTon5();
        }
    }



    class Test
    {

        static void Main(string[] args)
        {
            SingleTon5 s1 = SingleTon5.Instance;
            SingleTon5 s2 = SingleTon5.Instance;
            if (s1 == s2)
            {
                Console.WriteLine("equal");
            }
        }
    }
}

