using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace program3
{
    class Program
    {
        static void Main(string[] args)
        {
            List<string> fruits = new List<string>();
            fruits.Add("apple");
            fruits.Add("banana");
            fruits.Add("carrot");
            IEnumerator<string> myEnumerator = fruits.GetEnumerator();
            while(myEnumerator.MoveNext())
            {
                Console.Write("\t{0}",myEnumerator.Current);
                Console.WriteLine();
            }
        }
    }
}
