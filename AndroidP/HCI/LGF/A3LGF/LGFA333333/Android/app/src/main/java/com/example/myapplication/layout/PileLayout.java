package com.example.myapplication.layout;

import com.example.myapplication.drawing.pre.VisualElement;

import java.util.ArrayList;
import java.util.List;

public class PileLayout extends Layout {
    float x, y,  w, h;
    public PileLayout(float x, float y, float w, float h){
        this.x = x;
        this.y = y;
        this.w = w;
        this.h = h;
    }

    @Override
    public void doLayout(List<VisualElement> children, VisualElement element) {
        for (VisualElement ele:children){
            ele.setX(element.getX());
            ele.setY(element.getY());
        }


//        List<Float> listHeight = new ArrayList<>();
//        List<Float> listWidth = new ArrayList<>();
//        for (VisualElement ele:children){
//            listHeight.add(ele.getH());
//            listWidth.add(ele.getW());
//        }
//        float maxH = listHeight.get(0);
//        float maxW = listWidth.get(0);
//        for (int i = 0; i < listHeight.size(); i++) {
//            if (maxH <= listHeight.get(i)) maxH = listHeight.get(i);
//            if (maxW <= listWidth.get(i)) maxW = listWidth.get(i);
//        }


        element.setW(w);
        element.setH(h);
        element.setX(x);
        element.setY(y);

    }
}
