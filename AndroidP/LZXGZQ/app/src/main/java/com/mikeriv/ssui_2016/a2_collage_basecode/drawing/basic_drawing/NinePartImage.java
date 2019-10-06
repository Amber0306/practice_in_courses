package com.mikeriv.ssui_2016.a2_collage_basecode.drawing.basic_drawing;

import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.NinePatch;
import android.graphics.Paint;
import android.graphics.Rect;

import com.mikeriv.ssui_2016.a2_collage_basecode.drawing.BaseVisualElement;

public class NinePartImage extends BaseVisualElement {

    private NinePatch ninePatch;
    private Paint paint;
    private Rect rect;

    public NinePartImage(float x, float y, float w, float h, NinePatch patches){
        this.x0=x;
        this.y0=y;
        this.w0=w;
        this.h0=h;
        this.ninePatch=patches;
    }

    @Override
    public void draw(Canvas onCanvas){
        rect = new Rect((int)this.x0, (int)this.y0, (int)(this.getW()+this.x0),(int)(this.getH()+this.y0));
        paint=new Paint();
        paint.setColor(Color.WHITE);
        onCanvas.save();
        ninePatch.draw(onCanvas, rect, paint);
        onCanvas.restore();
    }
}
