package com.example.myapplication.drawing;

import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;

import com.example.myapplication.drawing.pre.BasicVisualElement;

public class SolidBackDrop extends BasicVisualElement {
    int colorint;

    public SolidBackDrop(float x, float y, float w, float h, int color){
        setX(x);
        setY(y);
        setW(w);
        setH(h);
        colorint=color;
    }

    public void  setColor(int color){
        colorint=color;
    }

    public int getColor(){
        return colorint;
    }

    @Override
    public void draw(Canvas onCanvas){
        super.draw(onCanvas);
        Paint p = new Paint();
        p.setColor(Color.BLACK);
        p.setStyle(Paint.Style.FILL);
        onCanvas.drawRect(getX(),getY(),getX()+getW(),getY()+getH(),p);
    }
}
