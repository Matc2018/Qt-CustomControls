/************************双滑块滚动条*****顾逸凡 2019.7.5*********/
#pragma once
#include <QWidget>
#include "SliderBar.h"

namespace Ui
{
	class DoubleHandleSlider;
}

class SLIDERBAR_EXPORT DoubleHandleSlider: public QWidget
{
	Q_OBJECT
public:
	DoubleHandleSlider(QWidget *parent = Q_NULLPTR);
	~DoubleHandleSlider();

	/*****************必要初始化接口*****************/
	//设置滚动条，杆子的宽度
	void SetSliveWidth(int value);
	//设置杆子颜色以及背景颜色
	void SetBackgrondColor(QColor slive_color, QColor slider_color, QColor slive_color_bottom);
	//设置滑动条杆子到上下边的距离
	void SetTopAndBottomBlank(int top_value, int bottom_value);
	//设置滑块的宽和高
	void SetSliderWidgetWidthAndHeight(int width, int height);
	//设置滑块的范围
	void SetSliderRange(int min_value, int max_value);
	//设置杆子圆角程度
	void SetSliveRoundValue(int x_value, int y_value);
	
	
	//设置小滑块字体，字体颜色，背景色
	void SetMinHanderLabelProperty(QFont font, QColor font_color, QColor back_color);
	//设置小滑块圆角程度
	void SetMinHanderLabelRoundValue(int border_x_value, int border_y_value);

	//设置大滑块字体，字体颜色，背景色
	void SetMaxHanderLabelProperty(QFont font, QColor font_color, QColor back_color);
	//设置小滑块圆角程度
	void SetMaxHanderLabelRoundValue(int border_x_value, int border_y_value);


	//如若改变了上述参数请调用以下函数，第一次不需要调用(因为在resize里调用了)
	void Update();
	/***********************控制接口***********************/
	void SetMinSliderValue(int value);
	void SetMaxSliderValue(int value);
signals:
	void MinHandleValueChange(int cur_value);
	void MaxHandleValueChange(int cur_value);

private:
	Ui::DoubleHandleSlider *ui;
	void resizeEvent(QResizeEvent* size); //窗口大小改变事件，用于得到正确的控件长和宽
	void paintEvent(QPaintEvent* event);//用于画背景

	void MoveMinSlider(int min_handle_value);//移动小滑块到固定值
	void MoveMaxSlider(int max_handle_value);//移动大滑块到固定值

	bool eventFilter(QObject *obj, QEvent *event);
	void leaveEvent(QEvent* event);
	void mouseMoveEvent(QMouseEvent* event);

	/**********************滑块状态********************/

	enum HanderState
	{
		UnCheck_State, //无选中状态
		MinHandleChecked_State,//小滑块选中状态
		MaxHandleChecked_State//大滑块状态
	};

	/********************设置背景属性*******************/
	int m_width; //整个控件宽
	int m_height;//整个控件高

	int slive_width;//滚动条，杆子的宽度

	QColor slive_color;  //杆子颜色
	QColor slive_color_bottom; //设置滑块划过的杆子颜色
	QColor slider_color;  //背景颜色

	int top_value;//设置滑动条杆子到上边界的距离
	int bottom_value;//设置滑动条杆子到下边界的距离

	int round_value_x; //滑块x轴圆角数值
	int round_value_y; //滑块y轴圆角数值

	/*******************设置滑块属性******************/
	QRoundedLabel *min_handle_lab; //小滑块
	QRoundedLabel *max_handle_lab; //大滑块
	
	//以下值-小滑块和大滑块共用
	int wid_width;//滑块宽度
	int wid_height;//滑块高度

	int min_value;//滑块最小值
	int max_value;//滑块最大值
	
	int cur_min_value;//小滑块当前值
	int cur_max_value;//大滑块当前值

	int hander_x_axis;//滑块固定下来的x轴
	int hander_y_dis; //滑块从最小值到最大值划过的总距离(实际上等于杆子的长度)

	double haner_y_step;//滑块移动的步长(滑块移动1个整数单位移动的像素值)

	HanderState cur_state; //滑块当前的状态
};
