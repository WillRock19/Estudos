﻿using System;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Imaging;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using draw = System.Drawing;


namespace PGM_EDITOR
{
    public static class tools
    {

        public static PgmImg Average(PgmImg pgm)
        {
            var ret = pgm.Clone();

            for (int i = 0; i < pgm.Width; i++)
                for (int j = 0; j < pgm.Height; j++)
                    ret[i, j] = LocalAverage(pgm, i, j);

            return ret;
        }


        private static byte LocalAverage(PgmImg img,int x,int y)
        {
            double media = 0;
            var aux = (int)img.ReduceTo / 2;

            for (int i = x - aux; i <= x + aux; i++)
                for (int j = y - aux; j <= y + aux; j++)
                    if (j < img.Height && j >= 0 && i >= 0 && i < img.Width)
                        media += (double)img[i, j];
   
            return (byte)Math.Round((double)media/Math.Pow(img.ReduceTo,2));
        }

        public static PgmImg Equalize(PgmImg pgm)
        {

            var min = pgm.Pallete.Min();
            var Acumulativo = pgm.CumulativePallete();
            var max = Acumulativo[255];
            var ret = pgm.Clone();

     
           

            for (int i = 0; i < pgm.Width; i++)
                for (int j = 0; j < pgm.Height; j++)
                    ret[i, j] = (byte) (
                                            (
                                                (double)
                                                (Acumulativo[pgm[i, j]] - min) /
                                                (max - min) 
                                            )
                                        *255);   

            return ret;

        }

 

        public static PgmImg ReduceColors(PgmImg pgm)
        {
            var temp = pgm.Clone();
            

            for (int i = 0; i < pgm.Width; i++)
                for (int j = 0; j < pgm.Height; j++)
                    temp[i, j] = Reduce(pgm[i,j], pgm.ReduceTo);


            /*
            // outra forma - mais lenta
           var newColorArray = new int[pgm.ReduceTo];
           for (int i = 0; i < pgm.ReduceTo ; i++)
               newColorArray[i] = i * (255 / (pgm.ReduceTo-1));
            
           for (int i = 0; i < matrix.GetLength(0); i++)
               for (int j = 0; j < matrix.GetLength(1); j++)
                   temp[i, j] = (byte)Closest((int)matrix[i, j], newColorArray);  
           */
            
                    
            return temp;
        }

        public static PgmImg FloydSteinberg(PgmImg pgm)
        {


            var temp = pgm.Clone();
            
            var width = temp.Width-1;
            var height = temp.Height-1;

            for (int i = 0; i < temp.Width; i++)
                for (int j = 0; j < temp.Height; j++)
                {
                    var original = temp[i, j];
                    temp[i, j] = Reduce(temp[i, j], pgm.ReduceTo);
                    var error = (double)original - (double)temp[i, j];

                    if (j < height)
                        temp[i, j + 1] = Normalize(temp[i + 0, j + 1] + error * MagicNumbers.Right);

                    if (i < width)
                        temp[i + 1, j ] = Normalize(temp[i + 1, j + 0] + error * MagicNumbers.Down);

                    if (j < height && i < width)
                        temp[i + 1, j + 1] = Normalize(temp[i + 1, j + 1] + error * MagicNumbers.DownRight);

                    if (j > 0 && i < width)
                        temp[i + 1, j - 1] = Normalize(temp[i + 1, j - 1] + error * MagicNumbers.DownLeft);

                }

            return temp;
        }


        private static byte Reduce(byte value, int colors)
        {
            byte ret;
            ret = (byte)Math.Round((colors - 1) * (double)value / 255);
            ret = (byte)Math.Round(255 * (double)ret / (colors - 1));

            return ret;
        }

        private static byte Normalize(double color)
        {
            return (byte)(color > 255 ? 255 : (color < 0 ? 0 : color));
        }

        private static int Closest(int closest, int[] values)
        {
            int indice = values.Count()-1;
            int minDiff = values[indice];
            

            for (int i = 0; i < values.Length; i++)
            {
                if (Math.Abs(closest - values[i]) <= minDiff)
                {
                    minDiff = Math.Abs(closest - values[i]);
                    indice = i;
                }

            }

            return values[indice];

            
        }

        public static PgmImg Transpose(PgmImg pgm)
        {
         
            var temp = new PgmImg(pgm.Height, pgm.Width);

            for (int i = 0; i < pgm.Width; i++)
                for (int j = 0; j < pgm.Height; j++)
                    temp[j, i] = pgm[i, j];


            return temp;
        }

        public static PgmImg MirrorX(PgmImg pgm)
        {
            var temp = pgm.Clone();

            for (int i = 0; i < pgm.Width; i++)
                for (int j = 0; j < pgm.Height; j++)
                    temp[i, j] = pgm[pgm.Width-1-i, j];

            return temp;

        }

        public static PgmImg MirrorY(PgmImg pgm)
        {

            var temp = pgm.Clone();

            for (int i = 0; i < pgm.Width; i++)
                for (int j = 0; j < pgm.Height; j++)
                    temp[i, j] = pgm[i, pgm.Height - 1 - j];

            return temp;

        }

        public static PgmImg RotateR(PgmImg bitmap)
        {
            var ret = MirrorX(Transpose(bitmap));            
            return ret;
        }

        public static PgmImg RotateL(PgmImg bitmap)
        {
            var ret = MirrorY(Transpose(bitmap));
            return ret;
        }

    }
}
