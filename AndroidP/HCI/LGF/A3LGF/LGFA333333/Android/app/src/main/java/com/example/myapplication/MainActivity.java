package com.example.myapplication;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Color;
import android.graphics.NinePatch;
import android.graphics.Typeface;
import android.support.constraint.ConstraintLayout;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.view.WindowManager;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.RelativeLayout;

import com.example.myapplication.drawing.IconImage;
import com.example.myapplication.drawing.NinePartImage;
import com.example.myapplication.drawing.SimpleFrame;
import com.example.myapplication.drawing.SolidBackDrop;
import com.example.myapplication.drawing.TextVisualElement;
import com.example.myapplication.layout.CircleLayout;
import com.example.myapplication.layout.ColumnLayout;
import com.example.myapplication.layout.PileLayout;
import com.example.myapplication.layout.RowLayout;
import com.example.myapplication.views.CollageView;

public class MainActivity extends AppCompatActivity {

    CollageView collageView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //得到布局
        final RelativeLayout layout = findViewById(R.id.layout);
        //得到测试按钮
        Button rowBtn = findViewById(R.id.rowBtn);
        Button columnBtn = findViewById(R.id.columnBtn);
        Button pileBtn = findViewById(R.id.pileBtn);
        Button circleBtn = findViewById(R.id.circleBtn);
        final CheckBox isClip = findViewById(R.id.isClip);

        rowBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                layout.removeView(collageView);
                //创建CollageView
                collageView = new CollageView(MainActivity.this);
                //创建bitmap
                Bitmap iconBitmap = BitmapFactory.decodeResource(getResources(),R.mipmap.a1);
                Bitmap nineBitmap = BitmapFactory.decodeResource(getResources(),R.drawable.a2);
                NinePatch ninePatch = new NinePatch(nineBitmap,nineBitmap.getNinePatchChunk(),null);
                //创建simpleFrame
                SimpleFrame simpleFrame = new SimpleFrame();
                simpleFrame.addChild(new SimpleFrame(0,0,100,100));
                simpleFrame.addChild(new TextVisualElement(0,0,"hhhhh", Typeface.DEFAULT,50));
                simpleFrame.addChild(new SolidBackDrop(0,0,100,100,Color.BLACK));
                simpleFrame.addChild(new IconImage(20,20,iconBitmap));
                simpleFrame.addChild(new NinePartImage(0,0,200,200,ninePatch));
                simpleFrame.layout = new RowLayout(0,0,1000,800);
                simpleFrame.setOvalclip(isClip.isChecked());
                //把创建VisualElement填入创建CollageView
                collageView.setChildVisualElement(simpleFrame);


                //把创建CollageView放入布局中
                layout.addView(collageView);
            }
        });


        columnBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                layout.removeView(collageView);
                //创建CollageView
                collageView = new CollageView(MainActivity.this);
                //创建bitmap
                Bitmap iconBitmap = BitmapFactory.decodeResource(getResources(),R.mipmap.a1);
                Bitmap nineBitmap = BitmapFactory.decodeResource(getResources(),R.drawable.a2);
                NinePatch ninePatch = new NinePatch(nineBitmap,nineBitmap.getNinePatchChunk(),null);
                //创建simpleFrame
                SimpleFrame simpleFrame = new SimpleFrame();
                simpleFrame.addChild(new SimpleFrame(0,0,100,100));
                simpleFrame.addChild(new TextVisualElement(0,0,"hhhhh", Typeface.DEFAULT,50));
                simpleFrame.addChild(new SolidBackDrop(0,0,100,100,Color.BLACK));
                simpleFrame.addChild(new IconImage(20,20,iconBitmap));
                simpleFrame.addChild(new NinePartImage(0,0,200,200,ninePatch));
                simpleFrame.layout = new ColumnLayout(0,0,500,1000);
                simpleFrame.setOvalclip(isClip.isChecked());
                //把创建VisualElement填入创建CollageView
                collageView.setChildVisualElement(simpleFrame);


                //把创建CollageView放入布局中
                layout.addView(collageView);
            }
        });



        pileBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                layout.removeView(collageView);
                //创建CollageView
                collageView = new CollageView(MainActivity.this);
                //创建bitmap
                Bitmap iconBitmap = BitmapFactory.decodeResource(getResources(),R.mipmap.a1);
                Bitmap nineBitmap = BitmapFactory.decodeResource(getResources(),R.drawable.a2);
                NinePatch ninePatch = new NinePatch(nineBitmap,nineBitmap.getNinePatchChunk(),null);
                //创建simpleFrame
                SimpleFrame simpleFrame = new SimpleFrame();
                simpleFrame.addChild(new SimpleFrame(0,0,500,500));
                simpleFrame.addChild(new TextVisualElement(0,0,"hhhhh", Typeface.DEFAULT,100));
                simpleFrame.addChild(new SolidBackDrop(0,0,300,300,Color.BLACK));
                simpleFrame.addChild(new IconImage(20,20,iconBitmap));
                simpleFrame.addChild(new NinePartImage(0,0,150,150,ninePatch));
                simpleFrame.layout = new PileLayout(100,100,800,800);
                simpleFrame.setOvalclip(isClip.isChecked());
                //把创建VisualElement填入创建CollageView
                collageView.setChildVisualElement(simpleFrame);


                //把创建CollageView放入布局中
                layout.addView(collageView);
            }
        });

        circleBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                layout.removeView(collageView);
                //创建CollageView
                collageView = new CollageView(MainActivity.this);
                //创建bitmap
                Bitmap iconBitmap = BitmapFactory.decodeResource(getResources(),R.mipmap.a1);
                Bitmap nineBitmap = BitmapFactory.decodeResource(getResources(),R.drawable.a2);
                NinePatch ninePatch = new NinePatch(nineBitmap,nineBitmap.getNinePatchChunk(),null);
                //创建simpleFrame
                SimpleFrame simpleFrame = new SimpleFrame();
                simpleFrame.addChild(new SimpleFrame(0,0,100,100));
                simpleFrame.addChild(new TextVisualElement(0,0,"hhhhh", Typeface.DEFAULT,50));
                simpleFrame.addChild(new SolidBackDrop(0,0,100,100,Color.BLACK));
                simpleFrame.addChild(new IconImage(20,20,iconBitmap));
                simpleFrame.addChild(new NinePartImage(0,0,200,200,ninePatch));
                simpleFrame.layout = new CircleLayout(0,0,800,800,300,300,200);
                simpleFrame.setOvalclip(isClip.isChecked());
                //把创建VisualElement填入创建CollageView
                collageView.setChildVisualElement(simpleFrame);
                //把创建CollageView放入布局中
                layout.addView(collageView);
            }
        });



    }
}
