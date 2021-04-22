using System;
using System.Linq;

namespace _09._Codeforces___Circular_RMQ
{
    public class Node
    {
        public bool isMarked = false;
        public int dS = 0;
        public int mini;
    }
    class Program
    {
        private static int n, m;
        private static int[] a;
        private static Node[] t;
        private static int l, r, x;

        static void build(int v, int tl, int tr)
        {
            if (tl == tr)
            {
                t[v].mini = a[tl];
                //cout <<"tl " <<tl <<" tr " <<tr <<" m " <<t[v].mini <<endl;
                return;
            }

            int mid = tl + ((tr - tl) >> 1),
            le = v + 1, ri = v + ((mid - tl + 1) << 1);
            build(le, tl, mid);
            build(ri, mid + 1, tr);
            t[v].mini = Math.Min(t[le].mini, t[ri].mini);
            //cout <<"tl " <<tl <<" tr " <<tr <<" m " <<t[v].mini <<endl;
        }

        static void push(int v, int le, int ri)
        {
            t[le].dS += t[v].dS;
            t[ri].dS += t[v].dS;
            t[le].mini += t[v].dS;
            t[ri].mini += t[v].dS;
            t[le].isMarked = t[ri].isMarked = true;
            t[v].isMarked = false;
        }

        static void inc(int v, int tl, int tr)
        {
            if (l > tr || r < tl) return; //totally outside
            if (tl == tr)
            {
                t[v].mini += x;
            }
            if (l <= tl && tr <= r) //totally inside
            {
                t[v].isMarked = true;
                t[v].dS += x;
                t[v].mini += x;
                //Console.WriteLine("tl " + tl + " tr " + tr + " m " + t[v].mini + " ds " + t[v].dS + " mark " + t[v].isMarked);
                return;
            }

            int mid = tl + ((tr - tl) >> 1),
            le = v + 1, ri = v + ((mid - tl + 1) << 1);
            if (t[v].isMarked)
            {
                push(v, le, ri);
            }

            inc(le, tl, mid);
            inc(ri, mid + 1, tr);
            //Console.WriteLine("tl " + tl + " tr " + tr + " m " + t[v].mini + " ds " + t[v].dS + " mark " + t[v].isMarked);
        }

        static int rmq(int v, int tl, int tr)
        {
            if (l > tr || r < tl) return int.MaxValue;
            if (l <= tl && tr <= r)
            {
                return t[v].mini;
            }

            int mid = tl + ((tr - tl) >> 1),
            le = v + 1, ri = v + ((mid - tl + 1) << 1);
            if (t[v].isMarked)
            {
                push(v, le, ri);
            }

            return Math.Min(rmq(le, tl, mid),
                       rmq(ri, mid + 1, tr));
        }

        static void Main(string[] args)
        {
            n = int.Parse(Console.ReadLine());
            a = Console.ReadLine()
                .Split(" ", StringSplitOptions.RemoveEmptyEntries)
                .Select(int.Parse)
                .ToArray();

            t = new Node[n << 1];
            for(int i = 0; i < t.Length; i++)
            {
                t[i] = new Node();
            }

            build(1, 0, n - 1);
            //*
            m = int.Parse(Console.ReadLine());
            while (m-- > 0)
            {
                var pars = Console.ReadLine()
                    .Split(" ", StringSplitOptions.RemoveEmptyEntries)
                    .Select(int.Parse)
                    .ToArray();
                l = pars[0];
                r = pars[1];
                if (pars.Length == 3) //inc
                {
                    x = pars[2];
                    //Console.WriteLine("l " + l + " r " + r + " x " + x);
                    if (r < l)
                    {
                        int lCopy = l;
                        l = 0;
                        inc(1, 0, n - 1);
                        l = lCopy;
                        r = n - 1;
                        inc(1, 0, n - 1);
                    }
                    else inc(1, 0, n - 1);
                }
                else //rmq
                {
                    //Console.WriteLine("l " + l + " r " + r);
                    if (r < l)
                    {
                        int lCopy = l;
                        l = 0;
                        int left = rmq(1, 0, n - 1);
                        l = lCopy;
                        r = n - 1;
                        Console.WriteLine(Math.Min(left, rmq(1, 0, n - 1)));
                    }
                    else
                    {
                        Console.WriteLine(rmq(1, 0, n - 1));
                    }
                }
            }
        }

    }
}
