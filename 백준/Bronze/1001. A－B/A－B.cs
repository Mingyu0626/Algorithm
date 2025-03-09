using System;
using System.IO;
using System.Collections.Generic;
using System.Text;

namespace BaekJoonCSharp
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split();

            int A = int.Parse(input[0]);
            int B = int.Parse(input[1]);
            Console.WriteLine(A - B);
        }
    }
}
