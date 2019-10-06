package com.example.myapplication.drawing;

import android.graphics.Canvas;
import android.graphics.NinePatch;
import android.graphics.Rect;

import com.example.myapplication.drawing.pre.BasicVisualElement;

public class NinePartImage extends BasicVisualElement {
    NinePatch patch;
    public NinePartImage(float x, float y, float w, float h, NinePatch patches){
        setX(x);
        setY(y);
        setW(w);
        setH(h);
        patch=patches;
    }

    public void  setPatch(NinePatch patches){
        patch=patches;
    }

    public NinePatch getPatch(){
        return patch;
    }
    @Override
    public void draw(Canvas onCanvas) {
        super.draw(onCanvas);
        patch.draw(onCanvas,new Rect((int)getX(),(int)getY(),(int)(getX()+getW()),(int)(getY()+getH())));
    }
}
