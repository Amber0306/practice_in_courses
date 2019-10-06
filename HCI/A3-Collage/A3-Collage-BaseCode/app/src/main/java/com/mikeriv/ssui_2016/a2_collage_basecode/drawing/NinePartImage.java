package com.mikeriv.ssui_2016.a2_collage_basecode.drawing;

import android.graphics.Canvas;
import android.graphics.NinePatch;
import android.graphics.RectF;

public class NinePartImage extends BaseVisualElement{
    private NinePatch MyNinePatch;
    public NinePartImage(float xLoc, float yLoc, float width, float height, NinePatch MyNinePatch){
        super(xLoc, yLoc, width, height);
        this.MyNinePatch = MyNinePatch;
    }
    @Override
    public void draw(Canvas onCanvas) {
        if (MyNinePatch != null){
            MyNinePatch.draw(onCanvas, new RectF(0, 0, getW(), getH()));
        }
        super.draw(onCanvas);
    }
}
