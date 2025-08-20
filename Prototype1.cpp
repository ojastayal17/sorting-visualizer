//#include <SFML/Graphics.hpp>
//#include <iostream>
//#include <vector>
//#include <random>
//#include <chrono>
//#include <thread>
//#include <string>
//
//using namespace sf;
//using namespace std;
//
//enum Screen{x=1920,y=1080};
//
//int startX = 550;
//int startY = 20;
//
//float speed = 10;
//int rectNum = 150;
//float rectSize = 5.0f;
//int rectStart = 7;
//int rectScale = 2;
//
//
//class SliderSFML
//{
//	sf::RectangleShape slider;
//	sf::RectangleShape axis;
//	sf::Font font;
//	sf::Text text;
//	int minValue;
//	int maxValue;
//	int xCord;
//	int yCord;
//	int axisWidth;
//	int axisHeight;
//	int sliderWidth;
//	int sliderHeight;
//	float sliderValue;
//public:
//	SliderSFML(int x, int y);
//	sf::Text returnText(int x, int y, std::string z, int fontSize);
//	void create(int min, int max);
//	void logic(sf::RenderWindow &window);
//	float getSliderValue();
//	void setSliderValue(float newValue);
//	void setSliderPercentValue(float newPercentValue);
//	void draw(sf::RenderWindow & window);
//};
//
//SliderSFML::SliderSFML(int x, int y)
//{
//	xCord = x;
//	yCord = y;
//	axisHeight = 10;
//	axisWidth = 150;
//	sliderWidth = 60;
//	sliderHeight = 30;
//
//	if (!font.loadFromFile("Fonts\\Neon.ttf"))
//		std::cout << "Error loading font\n";
//
//	text.setFont(font);
//	text.setFillColor(sf::Color::White);
//
//	axis.setPosition(x, y);
//	axis.setOrigin(0, axisHeight / 2);
//	axis.setSize(sf::Vector2f(axisWidth, axisHeight));
//	axis.setFillColor(sf::Color(63,63,63));
//	slider.setPosition(x, y);
//	slider.setOrigin(sliderWidth / 2, sliderHeight / 2);
//	slider.setSize(sf::Vector2f(sliderWidth, sliderHeight));
//	slider.setFillColor(sf::Color(192,192,192));
//}
//
//sf::Text SliderSFML::returnText(int x, int y, std::string z, int fontSize)
//{
//	text.setCharacterSize(fontSize);
//	text.setPosition(x, y);
//	text.setString(z);
//	return text;
//}
//
//void SliderSFML::create(int min, int max)
//{
//	sliderValue = min;
//	minValue = min;
//	maxValue = max;
//}
//
//void SliderSFML::logic(sf::RenderWindow &window)
//{
//	if (slider.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)
//		&& sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
//	{
//		if (sf::Mouse::getPosition(window).x >= xCord && sf::Mouse::getPosition(window).x <= xCord + axisWidth)
//		{
//			slider.setPosition(sf::Mouse::getPosition(window).x, yCord);
//			sliderValue = (minValue + ((slider.getPosition().x - xCord) / axisWidth * (maxValue - minValue)));
//		}
//	}
//}
//
//float SliderSFML::getSliderValue()
//{
//	return sliderValue;
//}
//
//void SliderSFML::setSliderValue(float newValue)
//{
//	if (newValue >= minValue && newValue <= maxValue)
//	{
//		sliderValue = newValue;
//		float diff = maxValue - minValue;
//		float diff2 = newValue - minValue;
//		float zzz = axisWidth / diff;
//		float posX = zzz*diff2;
//		posX += xCord;
//		slider.setPosition(posX, yCord);
//	}
//}
//
//void SliderSFML::setSliderPercentValue(float newPercentValue)
//{
//	if (newPercentValue >= 0 && newPercentValue <= 100)
//	{
//		sliderValue = newPercentValue / 100 * maxValue;
//		slider.setPosition(xCord + (axisWidth*newPercentValue / 100), yCord);
//	}
//}
//
//void SliderSFML::draw(sf::RenderWindow &window)
//{
//	logic(window);
//	window.draw(returnText(xCord - 10, yCord + 5, std::to_string(minValue), 20));
//	window.draw(axis);
//	window.draw(returnText(xCord + axisWidth - 10, yCord + 5, std::to_string(maxValue), 20));
//	window.draw(slider);
//	window.draw(returnText(slider.getPosition().x - sliderWidth, slider.getPosition().y - sliderHeight,
//		std::to_string((int)sliderValue), 15));
//}
//
//typedef struct
//{
//    RectangleShape rect;
//    int value;
//    int isSorted=0;
//}rectangle;
//
//void drawMenu(RenderWindow *window, vector<Text> menu)
//{
//    for(int i=0;i<menu.size();i++)
//    {
//        window->draw(menu[i]);
//    }
//}
//
//void drawStates(RenderWindow *window, vector<rectangle> rectangles,int blue=-1,int red=-1)
//{
//    for(int i=0;i<rectangles.size();i++)
//    {
//        if(rectangles[i].isSorted)
//        {
//            rectangles[i].rect.setFillColor(Color::Green);
//        }
//        else if(i==red)
//        {
//            rectangles[i].rect.setFillColor(Color::Red);
//        }
//        else if(i==blue)
//        {
//            rectangles[i].rect.setFillColor(Color::Blue);
//        }
//        window->draw(rectangles[i].rect);
//    }
//}
//
//void resetRect(vector<rectangle> &rectangles, vector<int> values)
//{
//    for(int i=0;i<rectNum;i++)
//    {
//        rectangle r;
//        r.value = values[i];
//
//        RectangleShape temp(Vector2f(rectSize,r.value*rectScale));
//        temp.setFillColor(Color::White);
//        temp.setOutlineThickness(2);
//        temp.setOutlineColor(Color::Magenta);
//        temp.setPosition(startX+i*rectStart,startY);
//
//        r.rect = temp;
//
//        rectangles[i]=r;
//    }
//}
//
//void drawTimeTable(RenderWindow *window, vector<Text> sortTimes)
//{
//    for(int i=0;i<sortTimes.size();i++)
//    {
//        window->draw(sortTimes[i]);
//    }
//}
//
//void SelectionSort(vector<rectangle> &rectangles, RenderWindow &window, Text process, SliderSFML slider)
//{
//    int min_index;
//    for(int i=0; i<rectangles.size(); i++)
//    {
//        min_index = i;
//        for(int j=i+1; j<rectangles.size(); j++)
//        {
//            if(rectangles[j].value < rectangles[min_index].value)
//            {
//                min_index = j;
//
//            }
//            window.clear();
//            window.draw(process);
//            slider.draw(window);
//            speed = slider.getSliderValue();
//            drawStates(&window,rectangles,i,j);
//            std::this_thread::sleep_for(std::chrono::milliseconds((int)speed));//delay
//            window.display();
//
//        }
//
//        if (min_index != i)
//        {
//            //swap
//            swap(rectangles[min_index],rectangles[i]);
//            Vector2f temp = rectangles[min_index].rect.getPosition();
//            rectangles[min_index].rect.setPosition(rectangles[i].rect.getPosition());
//            rectangles[i].rect.setPosition(temp);
//
//
//        }
//
//        rectangles[i].isSorted = 1;
//    }
//}
//void InsertionSort(vector<rectangle> &rectangles, RenderWindow &window, Text process,SliderSFML slider)
//{
//    for(int i=1; i<rectangles.size(); i++)
//    {
//        int j=i;
//        int val = rectangles[i].value;
//
//        while(j>0 && rectangles[j-1].value>val)
//        {
//            swap(rectangles[j],rectangles[j-1]);
//            Vector2f temp = rectangles[j].rect.getPosition();
//            rectangles[j].rect.setPosition(rectangles[j-1].rect.getPosition());
//            rectangles[j-1].rect.setPosition(temp);
//            j--;
//
//            window.clear();
//            window.draw(process);
//            slider.draw(window);
//            speed = slider.getSliderValue();
//            drawStates(&window,rectangles,j-1,j);
//            std::this_thread::sleep_for(std::chrono::milliseconds((int)speed));//delay
//            window.display();
//
//        }
//
//    }
//}
//
//int main()
//{
//    RenderWindow window(VideoMode(Screen::x, Screen::y), "sorting visualizer");
//
//    Font font;
//
//    if(!font.loadFromFile("QueensidesMedium-x30zV.ttf"))
//    {
//        cout<<"error loading text";
//        return 1;
//    }
//
//    //menu texts
//    int n=6;
//    vector<Text> menu;
//
//    for(int i=0;i<n;i++)
//    {
//        Text item;
//        item.setFont(font);
//        item.setCharacterSize(25);
//
//        switch(i)
//        {
//
//            case 0:{
//                item.setString("Enter 1 for Selection sort");
//                item.setPosition(0,0);
//                break;
//            }
//            case 1:{
//                item.setString("Enter 2 for Insertion sort");
//                item.setPosition(0,50);
//                break;
//            }
//            case 2:{
//                item.setString("Enter 3 for Bubble sort");
//                item.setPosition(0,100);
//                break;
//            }case 3:{
//                item.setString("Enter 4 for Quick sort");
//                item.setPosition(0,150);
//                break;
//            }case 4:{
//                item.setString("Enter 5 for Merge sort");
//                item.setPosition(0,200);
//                break;
//            }
//            case 5:{
//                item.setString("Enter 6 for Cocktail sort");
//                item.setPosition(0,250);
//                break;
//            }
//        }
//
//        menu.push_back(item);
//    }
//
//    Text t;
//    t.setFont(font);
//    t.setCharacterSize(25);
//    t.setPosition(0,50);
//
//    Text process;
//    process.setFont(font);
//    process.setCharacterSize(25);
//    process.setString("Processing....");
//    process.setPosition(0,0);
//
//    vector<Text> sortTimes;
//
//    for(int i=0;i<n;i++)
//    {
//        Text sortTime;
//        sortTime.setFont(font);
//        sortTime.setCharacterSize(25);
//        sortTime.setString("0");
//
//        switch(i)
//        {
//
//            case 0:{
//                sortTime.setPosition(0,400);
//                break;
//            }
//            case 1:{
//                sortTime.setPosition(0,450);
//                break;
//            }
//            case 2:{
//                sortTime.setPosition(0,500);
//                break;
//            }case 3:{
//                sortTime.setPosition(0,550);
//                break;
//            }case 4:{
//                sortTime.setPosition(0,600);
//                break;
//            }
//            case 5:{
//                sortTime.setPosition(0,650);
//                break;
//            }
//        }
//
//
//        sortTimes.push_back(sortTime);
//    }
//
//
//    Text backMenu;
//    backMenu.setFont(font);
//    backMenu.setCharacterSize(25);
//    backMenu.setString("press 0 to back to menu");
//    backMenu.setPosition(0,0);
//
//    vector<rectangle> rectangles;
//    vector<int> values;
//    vector<rectangle> cpy;
//
//    //setting positions
//    for(int i=0;i<rectNum;i++)
//    {
//        values.push_back(i+1);
//    }
//
//    //creating copy rectangles
//    for(int i=0;i<rectNum;i++)
//    {
//        rectangle r;
//        r.value = values[i];
//
//        RectangleShape temp(Vector2f(rectSize,r.value*rectScale));
//        temp.setFillColor(Color::White);
//        temp.setOutlineThickness(2);
//        temp.setOutlineColor(Color::Magenta);
//        temp.setPosition(startX+i*rectStart,startY);
//
//        r.rect = temp;
//
//        cpy.push_back(r);
//    }
//
//    random_shuffle(values.begin(),values.end());
//
//    //creating rectangles
//    for(int i=0;i<rectNum;i++)
//    {
//        rectangle r;
//        r.value = values[i];
//
//        RectangleShape temp(Vector2f(rectSize,r.value*rectScale));
//        temp.setFillColor(Color::White);
//        temp.setOutlineThickness(2);
//        temp.setOutlineColor(Color::Magenta);
//        temp.setPosition(startX+i*rectStart,startY);
//
//        r.rect = temp;
//
//        rectangles.push_back(r);
//    }
//
//
//    SliderSFML slider(30,100);
//    slider.create(0,100);
//    slider.setSliderValue(10);
//
//
//    bool reset = false;
//    bool sorting = false;
//    bool sorted = false;
//    int type = 0;
//
//    while (window.isOpen())
//    {
//        Event event;
//
//        while (window.pollEvent(event))
//        {
//            if (event.type == Event::Closed)
//                window.close();
//            if(event.type == Event::KeyPressed)
//            {
//                //quit
//                if(Keyboard::isKeyPressed(Keyboard::Escape)){
//                    window.close();
//                }
//                if(Keyboard::isKeyPressed(Keyboard::Num0)){
//                    reset=true;
//                    sorting=false;
//                    sorted=false;
//                }
//                if(Keyboard::isKeyPressed(Keyboard::Num1)){
//                    sorting = true;
//                    type = 1;
//                }
//                if(Keyboard::isKeyPressed(Keyboard::Num2)){
//                    sorting = true;
//                    type = 2;
//                }
//                if(Keyboard::isKeyPressed(Keyboard::Num3)){
//                    sorting = true;
//                    type = 3;
//                }
//                if(Keyboard::isKeyPressed(Keyboard::Num4)){
//                    sorting = true;
//                    type = 4;
//                }
//                if(Keyboard::isKeyPressed(Keyboard::Num5)){
//                    sorting = true;
//                    type = 5;
//                }
//                if(Keyboard::isKeyPressed(Keyboard::Num6)){
//                    sorting = true;
//                    type = 6;
//                }
//                if(Keyboard::isKeyPressed(Keyboard::Num7)){
//                    sorting = true;
//                    type = 7;
//                }
//            }
//        }
//
//        window.clear();
//        drawMenu(&window,menu);
//
//        if(reset)
//        {
//            resetRect(rectangles,values);
//            window.clear();
//            drawMenu(&window,menu);
//            drawStates(&window,rectangles);
//            window.display();
//            reset = false;
//        }
//        else if(sorting && type == 1) // selection sort
//        {
//
//            if(!sorted)
//            {
//                clock_t start = clock();
//
//                SelectionSort(rectangles,window,process,slider);
//
//                clock_t finish = clock();
//
//                string time = to_string((double)(finish-start) / CLOCKS_PER_SEC);
//
//                t.setString("time taken: " +time);
//
//                sortTimes[type-1].setString(time);
//
//                sorted = true;
//            }
//            else
//            {
//                 window.clear();
//                 drawStates(&window,rectangles);
//                 window.draw(t);
//                 window.draw(backMenu);
//                 window.display();
//            }
//
//
//        }
//        else if(sorting && type == 2) // insertion sort
//        {
//             if(!sorted)
//            {
//                clock_t start = clock();
//
//                InsertionSort(rectangles,window,process,slider);
//
//                clock_t finish = clock();
//                string time = to_string((double)(finish-start) / CLOCKS_PER_SEC);
//
//                for(int i=0;i<rectangles.size();i++)
//                {
//                    rectangles[i].isSorted = 1;
//                    window.clear();
//                    window.draw(process);
//                    drawStates(&window,rectangles);
//                    std::this_thread::sleep_for(std::chrono::milliseconds(10));//delay
//                    window.display();
//                }
//
//
//
//                t.setString("time taken: " +time);
//
//                sortTimes[type-1].setString(time);
//
//                sorted = true;
//            }
//            else
//            {
//                 window.clear();
//                 drawStates(&window,rectangles);
//                 window.draw(t);
//                 window.draw(backMenu);
//
//                 window.display();
//            }
//
//
//        }
//        else if(sorting && type == 3) // bubble sort
//        {
//            if(!sorted)
//            {
//                clock_t start = clock();
//                int last_index = rectangles.size()-1;
//                for(int i=0;i<rectangles.size();i++)
//                {
//                    for(int j=0;j<rectangles.size()-i-1;j++)
//                    {
//                        if(rectangles[j].value > rectangles[j+1].value)
//                        {
//                            rectangle temp = rectangles[j];
//                            rectangles[j] = rectangles[j+1];
//                            rectangles[j+1] = temp;
//                            Vector2f temp1 = rectangles[j+1].rect.getPosition();
//                            rectangles[j+1].rect.setPosition(rectangles[j].rect.getPosition());
//                            rectangles[j].rect.setPosition(temp1);
//                        }
//
//                        window.clear();
//                        window.draw(process);
//                        drawStates(&window,rectangles,-1,j);
//                        std::this_thread::sleep_for(std::chrono::milliseconds((int)speed));//delay
//                        window.display();
//
//                    }
//                    rectangles[last_index-i].isSorted = 1;
//                }
//
//                clock_t finish = clock();
//
//                string time = to_string((double)(finish-start) / CLOCKS_PER_SEC);
//
//                t.setString("time taken: " +time);
//
//                sortTimes[type-1].setString(time);
//                sorted = true;
//            }
//            else
//            {
//                 window.clear();
//                 drawStates(&window,rectangles);
//                 window.draw(t);
//                 window.draw(backMenu);
//
//                 window.display();
//            }
//        }
//        else if(sorting && type == 6) //Cocktail Sort
//        {
//            if(!sorted)
//            {
//                clock_t start_time = clock();
//                bool swapped = true;
//                int sm,start = 0;
//                sm=start;
//                int end= rectangles.size() - 1;
//                int lar=end;
//                lar=lar-sm;
//                while (swapped)
//                {
//
//                    swapped = false;
//                    int i;
//                    for (i = start; i < end; ++i)
//                    {
//                        if (rectangles[i].value > rectangles[i + 1].value)
//                        {
//                            swap(rectangles[i+1],rectangles[i]);
//                         Vector2f temp = rectangles[i+1].rect.getPosition();
//                         rectangles[i+1].rect.setPosition(rectangles[i].rect.getPosition());
//                         rectangles[i].rect.setPosition(temp);
//                            swapped = true;
//                        }
//                        window.clear();
//                        window.draw(process);
//                        drawStates(&window,rectangles,-1,i);
//                        std::this_thread::sleep_for(std::chrono::milliseconds((int)speed));//delay
//                        window.display();
//
//                    }
//                   rectangles[lar].isSorted=true;
//                   lar--;
//                   if(!swapped)
//                     break;
//                    swapped = false;
//                        --end;
//                        for ( i = end - 1; i >= start; --i)
//                    {
//                        if (rectangles[i].value > rectangles[i + 1].value)
//                        {
//                            swap(rectangles[i+1],rectangles[i]);
//                         Vector2f temp = rectangles[i+1].rect.getPosition();
//                         rectangles[i+1].rect.setPosition(rectangles[i].rect.getPosition());
//                         rectangles[i].rect.setPosition(temp);
//                           swapped = true;
//                        }
//                        window.clear();
//                        window.draw(process);
//                        drawStates(&window,rectangles,-1,i);
//                        std::this_thread::sleep_for(std::chrono::milliseconds((int)speed));//delay
//                        window.display();
//                    }
//                    ++start;
//                   rectangles[sm].isSorted=true;
//                   sm++;
//                }
//                clock_t finish = clock();
//
//                string time = to_string((double)(finish-start) / CLOCKS_PER_SEC);
//
//                for(int i=0;i<rectangles.size();i++)
//                {
//                    if(!rectangles[i].isSorted)
//                    {
//                        rectangles[i].isSorted = 1;
//                        window.clear();
//                        window.draw(process);
//                        drawStates(&window,rectangles);
//                        std::this_thread::sleep_for(std::chrono::milliseconds(10));//delay
//                        window.display();
//                    }
//
//                }
//
//
//
//                t.setString("time taken: " +time);
//
//                sortTimes[type-1].setString(time);
//                sorted = true;
//            }
//            else
//            {
//                 window.clear();
//                 drawStates(&window,rectangles);
//                 window.draw(t);
//                 window.draw(backMenu);
//
//                 window.display();
//            }
//        }
//        else if(sorting && type == 7)
//        {
//             if(!sorted)
//            {
//                clock_t start = clock();
//                int n=rectangles.size();
//                int mx = rectangles[0].value;
//                for (int i = 1; i < n; i++)
//                    if (rectangles[i].value > mx)
//                        mx = rectangles[i].value;
//
//                for (int exp = 1; mx / exp > 0; exp *= 10) //START OF RADIX ALGO
//                {
//
//                    int i, count[10] = { 0 };
//                    vector <rectangle>  output;
//                    for(i=0; i<n; i++)
//                        output.push_back(rectangles[i]);
//
//                    for (i = 0; i < n; i++)
//                        count[(rectangles[i].value / exp) % 10]++; //Hash Table
//
//                    for (i = 1; i < 10; i++)
//                        count[i] += count[i - 1]; //Cumulative Array
//
//
//                    for (i = n - 1; i >= 0; i--)
//                    {
//                        output[count[(rectangles[i].value / exp) % 10] - 1].value = rectangles[i].value;
//                        output[count[(rectangles[i].value / exp) % 10] - 1].rect.setSize(rectangles[i].rect.getSize());
//                        count[(rectangles[i].value / exp) % 10]--;
//                    }
//                    for (i = 0; i < n; i++)
//                    {
//                        output[i].rect.setPosition(startX + i*rectStart,startY);
//                    }
//                    for (i = 0; i < n; i++)
//                    {
//                        window.clear();
//                        window.draw(process);
//                        drawStates(&window,rectangles,-1,i);
//                        std::this_thread::sleep_for(std::chrono::milliseconds((int)speed));//delay
//                        window.display();
//                        rectangles[i].value = output[i].value;
//                        rectangles[i].rect.setSize(output[i].rect.getSize());
//                        rectangles[i].rect.setPosition(output[i].rect.getPosition());
//                    }
//
//                }//EndS
//
//                clock_t finish = clock();
//                string time = to_string((double)(finish-start) / CLOCKS_PER_SEC);
//
//                t.setString("time taken: " +time);
//
//                sortTimes[type-1].setString(time);
//
//                for(int i=0;i<rectangles.size();i++)
//                {
//                    if(!rectangles[i].isSorted)
//                    {
//                        rectangles[i].isSorted = 1;
//                        window.clear();
//                        window.draw(process);
//                        drawStates(&window,rectangles);
//                        std::this_thread::sleep_for(std::chrono::milliseconds(10));//delay
//                        window.display();
//                    }
//
//                }
//
//                sorted = true;
//            }
//            else
//            {
//                 window.clear();
//                 drawStates(&window,rectangles);
//                 window.draw(t);
//                 window.draw(backMenu);
//                 window.display();
//            }
//        }
//        else
//        {
//            drawStates(&window,rectangles);
//            drawTimeTable(&window,sortTimes);
//            window.display();
//        }
//
//
//    }
//
//}
//
//
//
//
