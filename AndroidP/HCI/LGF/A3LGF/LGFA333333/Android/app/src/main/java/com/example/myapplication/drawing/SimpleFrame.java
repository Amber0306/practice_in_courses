package com.example.myapplication.drawing;

import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;

import com.example.myapplication.drawing.pre.BasicVisualElement;

public class SimpleFrame extends BasicVisualElement {


    public SimpleFrame() {
        this.x = 10;
        this.y = 10;
        this.width = 100;
        this.height = 100;
    }

    public SimpleFrame(float x, float y, float width, float height) {
        this.x = x;
        this.y = y;
        this.width = width;
        this.height = height;
    }



    @Override
    public void draw(Canvas onCanvas) {
        super.draw(onCanvas);
        Paint p = new Paint();
        p.setColor(Color.BLACK);// 设置灰色
        p.setStyle(Paint.Style.STROKE);//设置框
        p.setStrokeWidth(1);
//        onCanvas.drawRect(100, 100, 100, 100, p);// 正方形

        onCanvas.drawRect(x, y, x + width, y + height, p);// 正方形


    }
}
