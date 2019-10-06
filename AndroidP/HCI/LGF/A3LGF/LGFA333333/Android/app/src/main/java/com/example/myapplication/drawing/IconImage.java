package com.example.myapplication.drawing;

import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Matrix;
import android.graphics.Paint;
import android.graphics.drawable.shapes.RoundRectShape;


import com.example.myapplication.drawing.pre.BasicVisualElement;

public class IconImage extends BasicVisualElement {
    Bitmap rawimg;
    float defaulsize=250;

    public IconImage(float x, float y, Bitmap image){
        setX(x);
        setY(y);
        rawimg=image;
        setW(defaulsize*rawimg.getWidth()/rawimg.getHeight());
        setH(defaulsize);
    }

    public void  setImgSize(int color){
        defaulsize=color;
    }

    @Override
    public void draw(Canvas onCanvas) {
        super.draw(onCanvas);
        Matrix matrix = new Matrix();
        matrix.postScale((defaulsize*rawimg.getWidth())/(rawimg.getHeight()*rawimg.getWidth()), defaulsize/rawimg.getHeight());
        Bitmap img = Bitmap.createBitmap(rawimg,0,0,rawimg.getWidth(),rawimg.getHeight(),matrix,true);
        onCanvas.drawBitmap(img,getX(),getY(),new Paint());
    }
}
