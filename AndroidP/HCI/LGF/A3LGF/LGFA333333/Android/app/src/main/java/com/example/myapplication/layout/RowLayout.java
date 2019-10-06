package com.example.myapplication.layout;

import com.example.myapplication.drawing.pre.VisualElement;

import java.util.ArrayList;
import java.util.List;

public class RowLayout extends Layout {

    float x, y,  w, h;
    public RowLayout(float x, float y, float w, float h){
        this.x = x;
        this.y = y;
        this.w = w;
        this.h = h;
    }

    @Override
    public void doLayout(List<VisualElement> children, VisualElement element) {


        int x = (int) element.getX();
        int y = (int) element.getY();
        int w = 0;
        for (int i=0; i<children.size();i++){
            if (i-1>=0){
                x += children.get(i-1).getW();
            }
            w += children.get(i).getW();
            children.get(i).setX(x);
            children.get(i).setY(element.getY()+element.getH()/2 - children.get(i).getH()/2);
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
//
//
//        //设置父元素大小
//        element.setW(w);
//        element.setH(maxH);


        element.setW(this.w);
        element.setH(this.h);
        element.setX(this.x);
        element.setY(this.y);
    }
}
