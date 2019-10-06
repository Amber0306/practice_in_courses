package com.example.myapplication.views;

import android.database.sqlite.SQLiteBindOrColumnIndexOutOfRangeException;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Matrix;
import android.graphics.Paint;

import com.example.myapplication.drawing.pre.VisualElement;


public class OvalClip {
    float xx,yy,width,height;
    public OvalClip(float x, float y,float w,float h){
        xx=x;
        yy=y;
        width=w;
        height=h;
    }

    public void doClip(VisualElement element, Canvas onCanvas){
        float radius;
        radius=element.getW()/2;
        if(element.getH()<element.getW()) radius=element.getH()/2;
        Paint p =new Paint();
        p.setColor(Color.WHITE);
        p.setStyle(Paint.Style.FILL);
        onCanvas.drawCircle(element.getX()+element.getW()/2,element.getY()+element.getH()/2,radius,p);
    }
}
