using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace program2
{
    //1.声明参数类型
    public class DownloadEventArgs:EventArgs
    {
        public double Percent;
        //下载百分数
    }
    //2.声明委托类型
    public delegate void DownloadEventHandler(Object sender, DownloadEventArgs e);
    //3.定义事件源（下载器）
    public class Downloader
    {
        //4.声明事件
        public event DownloadEventHandler Downing;

        public void DoDownload()
        {
            double total = 1000;
            double already = 0;
            Random rnd = new Random();
            while(already<total)
            {
                System.Threading.Thread.Sleep(500);
                already += (rnd.NextDouble() / 4) * total;

                if (already > total) already = total;

                //4.每下载到一定结果，发生一个事件，即通知外界
                if(Downing!=null)
                {
                    DownloadEventArgs args = new DownloadEventArgs();
                    args.Percent = already / total;
                    Downing(this, args);
                }
            }
        } 
    }
    class Program
    {
        static void Main(string[] args)
        {
            var downloader = new Downloader();
            //5.注册事件
            downloader.Downing += ShowProgress;
            downloader.DoDownload();
        }
        //6.事件处理方法
        static void ShowProgress(object sender,DownloadEventArgs e)
        {
            Console.WriteLine($"Downloading. . . {e.Percent:##.#%}");
        }
    }
}
