package com.mikeriv.ssui_2016.a2_collage_basecode.drawing;

import android.graphics.Canvas;

import java.util.LinkedList;
import java.util.List;

public class BaseVisualElement extends PrebaseVisualElement {
    private float PositionX;
    private float PositionY;
    private boolean isIntrinsic;
    private float Width;
    private float Height;

    private VisualElement parent;
    List<VisualElement> childList;

    @Override
    public void setX(float x){
        PositionX = x;
    }

    @Override
    public void  setY(float y){
        PositionY = y;
    }

    @Override
    public float getX(){
        return PositionX;
    }

    @Override
    public float getY(){
        return PositionY;
    }

    @Override
    public void setW(float w){
        Width = w;
    }

    @Override
    public void setH(float h){
        Height = h;
    }

    @Override
    public float getH(){
        return Height;
    }

    @Override
    public float getW(){
        return Width;
    }

    @Override
    public boolean sizeIsIntrinsic() {
        return isIntrinsic;
    }

    @Override
    public VisualElement getParent(){
        return parent;
    }

    @Override
    public void setParent(VisualElement newElement){
        parent = newElement;
    }

    @Override
    public int getNumChildren() {
        return childList.size();
    }

    @Override
    public  VisualElement getChildAt(int index){
        if(index < 0 || index >= childList.size())
            return null;
        return childList.get(index);
    }

    @Override
    public int findChild(VisualElement element){
        if(element == null)
            return -1;
        return childList.indexOf(element);
    }

    @Override
    public void addChild(VisualElement element){
        childList.add(element);
    }

    @Override
    public void removeChildAt(int index){
        if(index >= 0 && index < childList.size())
            childList.remove(index);
    }

    @Override
    public void removeChild(VisualElement element){
        childList.remove(element);
    }

    @Override
    public void moveChildFirst(VisualElement element){
        if(childList.contains(element)){
            childList.remove(element);
            childList.add(0, element);
        }
    }

    @Override
    public void moveChildLast(VisualElement element){
        if (childList.contains(element)) {
            childList.remove(element);
            childList.add(element);
        }
    }

    @Override
    public void moveChildEarlier(VisualElement element){
        if(childList.contains(element)){
            int index = childList.indexOf(element);
            if(index > 0){
                childList.remove(element);
                childList.add(--index, element);
            }
        }
    }

    @Override
    public void moveChildLater(VisualElement element){
        if(childList.contains(element)){
            int index = childList.indexOf(element);
            if(index < childList.size()-1){
                childList.remove(element);
                childList.add(++index, element);
            }
        }
    }

    @Override
    public void doLayout(){

        if(!childList.isEmpty()) {
            for (VisualElement it : childList) {
                it.doLayout();
            }
        }
    }

    @Override
    public void draw(Canvas onCanvas){
        if(!childList.isEmpty()){
            for (VisualElement it: childList
                 ) {
                it.draw(onCanvas);
            }
        }
    }

    /*
     *Constructor
     */

    /*
    *Default Constructor
     */
    public BaseVisualElement(){
        this(0, 0);
    }

    public BaseVisualElement(float x, float  y){
        this(x, y, 13.7f, 13.9f);
    }

    public BaseVisualElement(float x, float y, float w, float h){
        PositionY = y;
        PositionX = x;
        Width = w;
        Height = h;
        isIntrinsic = false;
        childList = new LinkedList<>();
        parent = null;
    }
}
