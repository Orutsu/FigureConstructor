#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for (int i = 0, y = 0; i < 3; ++i, y+=200) {
        for (int j = 0, x = 280; j < 5; ++j, x+=200){
            figures[i*5+j].position.x = x;
            figures[i*5+j].position.y = y;
        }
    }

    labelForToolTip = new QLabel*[LIMIT_OF_FIGURES]{
        ui->cell1, ui->cell2, ui->cell3, ui->cell4, ui->cell5,
        ui->cell6, ui->cell7, ui->cell8, ui->cell9, ui->cell10,
        ui->cell11, ui->cell12, ui->cell13, ui->cell14, ui->cell15
    };
    SetVisibilityOfFields(false);
    ui->l1->setText("Розмір сторін");
    ui->l1->setVisible(true);
    ui->spin1->setVisible(true);
    ui->pushDrawFromUI->setVisible(true);
    ui->pushCancelDraw->setVisible(true);
    ui->px1->setVisible(true);
    this->setFixedSize(1280,600);
}

void MainWindow::SetVisibilityOfFields(bool visible)
{
    ui->spin1->setVisible(visible);
    ui->spin2->setVisible(visible);
    ui->spin3->setVisible(visible);
    ui->spinY1->setVisible(visible);
    ui->spinY2->setVisible(visible);
    ui->spinY3->setVisible(visible);
    ui->pushDrawFromUI->setVisible(visible);
    ui->pushCancelDraw->setVisible(visible);
    ui->l1->setVisible(visible);
    ui->l2->setVisible(visible);
    ui->l3->setVisible(visible);
    ui->ly1->setVisible(visible);
    ui->ly2->setVisible(visible);
    ui->ly3->setVisible(visible);
    ui->px1->setVisible(visible);
    ui->px2->setVisible(visible);
}

void MainWindow::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    for(int i = 0; i < LIMIT_OF_FIGURES; ++i){
        if (figures[i].type > 0) labelForToolTip[i]->setVisible(true);
        switch(figures[i].color){
            case Red:{
                painter.setBrush(QColor("darkRed"));
                break;
            }
            case Orange:{
                painter.setBrush(QColor("orange"));
                break;
            }
            case Yellow:{
                painter.setBrush(QColor("yellow"));
                break;
            }
            case Green:{
                painter.setBrush(QColor("darkGreen"));
                break;
            }
            case Blue:{
                painter.setBrush(Qt::blue);
                break;
            }
            case Purple:{
                painter.setBrush(QColor("purple"));
                break;
            }
            case Black:{
                painter.setBrush(Qt::black);
                break;
            }
        }
        switch(figures[i].type){
            case Square: {
                FSquare *temp = dynamic_cast<FSquare*>(figures[i].figure);
                painter.drawRect(QRect(temp->getX(), temp->getY(), temp->getSideSize(), temp->getSideSize()));
                labelForToolTip[i]->setToolTip("Квадрат:"
                                               "\n -Довжина сторони: " + QString::number(temp->getSideSize(), 'f', 2) + " px."
                                               "\n -Площа: " + QString::number(temp->findArea(), 'f', 2) + " px."
                                               "\n -Периметр: " + QString::number(temp->findPerimeter(), 'f', 2) + " px."
                                               "\n -Радіус описаного кола: " + QString::number(temp->findRadiusOfOutCircle(), 'f', 2) + " px."
                                               "\n -Радіус вписаного кола: " + QString::number(temp->findRadiusOfInCircle(), 'f', 2) + " px.");
                break;
            }
            case Rectangle:{
                FRectangle *temp = dynamic_cast<FRectangle*>(figures[i].figure);
                painter.drawRect(QRect(temp->getX(), temp->getY(), temp->getWidth(), temp->getHeight()));
                labelForToolTip[i]->setToolTip("Прямокутник:"
                                               "\n -Ширина: " + QString::number(temp->getWidth(), 'f', 2) + " px."
                                               "\n -Висота: " + QString::number(temp->getHeight(), 'f', 2) + " px."
                                               "\n -Площа: " + QString::number(temp->findArea(), 'f', 2) + " px."
                                               "\n -Периметр: " + QString::number(temp->findPerimeter(), 'f', 2) + " px."
                                               "\n -Радіус описаного кола: " + QString::number(temp->findRadiusOfOutCircle(), 'f', 2) + " px.");
                break;
            }
            case Circle:{
                FCircle *temp = dynamic_cast<FCircle*>(figures[i].figure);
                painter.drawEllipse(temp->getX(), temp->getY(), temp->getDiameter(), temp->getDiameter());
                labelForToolTip[i]->setToolTip("Коло:"
                                               "\n -Радіус: " + QString::number(temp->getDiameter() / 2.0, 'f', 2) + " px."
                                               "\n -Діаметр: "  + QString::number(temp->getDiameter(), 'f', 2) + " px."
                                               "\n -Площа: " + QString::number(temp->findArea(), 'f', 2) + " px."
                                               "\n -Периметр: " + QString::number(temp->findPerimeter(), 'f', 2) + " px."
                                               "\n -Площа описаного квадрата: " + QString::number(temp->getDiameter()*temp->getDiameter(), 'f', 2) + " px.");
                break;
            }
            case Triangle:{
                FTriangle *temp = dynamic_cast<FTriangle*>(figures[i].figure);
                QPolygon poly;
                poly << QPoint(temp->getX1(), temp->getY1()) << QPoint(temp->getX2(), temp->getY2()) << QPoint(temp->getX3(), temp->getY3());
                painter.drawPolygon(poly);
                labelForToolTip[i]->setToolTip("Трикутник:"
                                                 "\n -Довжина сторони AB: " + QString::number(temp->getSide1(), 'f', 2) + " px."
                                                 "\n -Довжина сторони BC: " + QString::number(temp->getSide2(), 'f', 2) + " px."
                                                 "\n -Довжина сторони AC: " + QString::number(temp->getSide3(), 'f', 2) + " px."
                                                 "\n -Кут A: " + QString::number(temp->findAngle2(), 'f', 2) + " градуси"
                                                 "\n -Кут B: " + QString::number(temp->findAngle3(), 'f', 2) + " градуси"
                                                 "\n -Кут C: " + QString::number(temp->findAngle1(), 'f', 2) + " градуси"
                                                 "\n -Площа: " + QString::number(temp->findArea(), 'f', 2) + " px."
                                                 "\n -Периметр: " + QString::number(temp->findPerimeter(), 'f', 2) + " px."
                                                 "\n -Радіус описаного кола: " + QString::number(temp->findRadiusOfOutCircle(), 'f', 2) + " px."
                                                 "\n -Радіус вписаного кола: " + QString::number(temp->findRadiusOfInCircle(), 'f', 2) + " px."
                                                 "\n -Довжина найбільшої середньої лінії: " + QString::number(temp->findMiddleLine(), 'f', 2) + " px.");
                QFont font = painter.font();
                font.setPointSize(12);
                painter.setFont(font);
                if (figures[i].color == 7) painter.setPen(QColor("orange"));
                else painter.setPen(Qt::black);
                painter.drawText(temp->getX1(), temp->getY1(), "A");
                painter.drawText(temp->getX2(), temp->getY2(), "B");
                painter.drawText(temp->getX3(), temp->getY3(), "C");
                painter.setPen(Qt::black);
                break;
            }
            case Ellipse:{
                FEllipse *temp = dynamic_cast<FEllipse*>(figures[i].figure);
                painter.drawEllipse(temp->getX(), temp->getY(), temp->getWidth(), temp->getHeight());
                labelForToolTip[i]->setToolTip("Еліпс:"
                                               "\n -Ширина: " + QString::number(temp->getWidth(), 'f', 2) + " px."
                                               "\n -Висота: " + QString::number(temp->getHeight(), 'f', 2) + " px."
                                               "\n -Площа: " + QString::number(temp->findArea(), 'f', 2) + " px."
                                               "\n -Периметр: " + QString::number(temp->findPerimeter(), 'f', 2) + " px.");
                break;
            }
            default:break;
        }
    }
}

int checkempty(FILE * fp) {
    long currentsize = ftell(fp);
    long checksize;
    fseek(fp, 0, SEEK_END);
    checksize = ftell(fp);
    if (!checksize) {
        return 0;
    }
    fseek(fp, currentsize, SEEK_SET);
    return 1;
}

void MainWindow::on_pushReadFile_clicked()
{
    for (int i = 0; i < LIMIT_OF_FIGURES; ++i){
        figures[i].type = 0;
        figures[i].figure = nullptr;
        labelForToolTip[i]->setVisible(false);
    }
    repaint();
    QString QFileName = QFileDialog :: getOpenFileName(this, "Open file","D:\\2 course\\kursova\\option17\\newFigureInfo");
    FILE *fp;
    try {
        if (!(fp = fopen(QFileName.toUtf8().constData(), "r"))) {
            throw "Неможливо відкрити файл!";
        }
        if (!checkempty(fp)) {
            throw "Файл пустий!";
        }
    } catch (const char *message) {
        QMessageBox::critical(nullptr, "Error", message);
        fclose(fp);
        return;
    }
    int figureCount = 0;
    while (!feof(fp)) {
        char source_buffer[80] = { 0 };
        fgets(source_buffer, 80, fp);
        if (source_buffer[0] == '\n' || source_buffer[0] == '\0') {
            continue;
        }
        int tempType = 0;
        int tempColor = 0;
        int tempSize1 = 0;
        int tempSize2 = 0;
        sscanf(source_buffer, "%d %d", &tempType, &tempColor);
        try {
            if (!tempType) throw "Заданий неправильний тип у " + to_string(figureCount + 1) + " фігурі!";
            if (tempColor < 1 || tempColor > 7) throw "Заданий неправильний колір у " + to_string(figureCount + 1) + " фігурі!";
            switch(tempType){
                case Square: {
                    sscanf(source_buffer, "%d %d %d", &tempType, &tempColor, &tempSize1);
                    if (!tempSize1) throw "Задані не всі параметри у " + to_string(figureCount + 1) + " фігурі!";
                    if (tempSize1 < 10 || tempSize1 > 190) throw "Вказано завеликий або замалий розмір (Має бути 10 < РОЗМІР < 190 px) у " + to_string(figureCount + 1) + " фігурі!";
                    figures[figureCount].type = Square;
                    FSquare *temp = new FSquare(figures[figureCount].position, tempSize1);
                    figures[figureCount].figure = temp;
                    break;
                }
                case Rectangle:{
                    sscanf(source_buffer, "%d %d %d %d", &tempType, &tempColor, &tempSize1, &tempSize2);
                    if (!tempSize1 || !tempSize2) throw "Задані не всі параметри у " + to_string(figureCount + 1) + " фігурі!";
                    if (tempSize1 < 10 || tempSize1 > 190 || tempSize2 < 10 || tempSize2 > 190) throw "Вказано завеликий або замалий розмір (Має бут 10 < РОЗМІР < 190 px) у " + to_string(figureCount + 1) + " фігурі!";
                    figures[figureCount].type = Rectangle;
                    FRectangle *temp = new FRectangle(figures[figureCount].position, tempSize1, tempSize2);
                    figures[figureCount].figure = temp;
                    break;
                }
                case Circle:{
                    sscanf(source_buffer, "%d %d %d", &tempType, &tempColor, &tempSize1);
                    if (!tempSize1) throw "Задані не всі параметри у " + to_string(figureCount + 1) + " фігурі!";
                    if (tempSize1 < 10 || tempSize1 > 190) throw "Вказано завеликий або замалий розмір (Має бут 10 < РОЗМІР < 190 px) у " + to_string(figureCount + 1) + " фігурі!";
                    figures[figureCount].type = Circle;
                    FCircle *temp = new FCircle(figures[figureCount].position, tempSize1);
                    figures[figureCount].figure = temp;
                    break;
                }
                case Triangle:{
                    int x1 = 0,x2 = 0,x3 = 0,y1 = 0,y2 = 0,y3 = 0;
                    sscanf(source_buffer, "%d %d %d %d %d %d %d %d", &tempType, &tempColor, &x1, &y1, &x2, &y2, &x3, &y3);
                    if (!x1||!x2||!x3||!y1||!y2||!y3) throw "Задані не всі координати трикутника у " + to_string(figureCount + 1) + " фігурі!";
                    if (x1<10||x2<10||x3<10||y1<10||y2<10||y3<10||x1>190||x2>190||x3>190||y1>190||y2>190||y3>190) {
                        throw "Вказано неправильні координати (Має бут 10 < КООРДИНАТИ < 190 px) у " + to_string(figureCount + 1) + " фігурі!";
                    }
                    figures[figureCount].type = Triangle;
                    Coordinates points[3];
                    points[0].x = x1;
                    points[0].y = y1;
                    points[1].x = x2;
                    points[1].y = y2;
                    points[2].x = x3;
                    points[2].y = y3;
                    FTriangle *temp = new FTriangle(figures[figureCount].position, points[0], points[1], points[2]);
                    figures[figureCount].figure = temp;
                    break;
                }
                case Ellipse:{
                    sscanf(source_buffer, "%d %d %d %d", &tempType, &tempColor, &tempSize1, &tempSize2);
                    if (!tempSize1 || !tempSize2) throw "Задані не всі параметри у " + to_string(figureCount + 1) + " фігурі!";
                    if (tempSize1 < 10 || tempSize1 > 190 || tempSize2 < 10 || tempSize2 > 190) throw "Вказано завеликий або замалий розмір (Має бут 10 < РОЗМІР < 190 px) у " + to_string(figureCount + 1) + " фігурі!";
                    figures[figureCount].type = Ellipse;
                    FEllipse *temp = new FEllipse(figures[figureCount].position, tempSize1, tempSize2);
                    figures[figureCount].figure = temp;
                    break;
                }
                default:{
                    throw "Заданий неправильний тип у " + to_string(figureCount + 1) + " фігурі!";
                }
            }
            figures[figureCount].color = tempColor;
        } catch (string message) {
            QMessageBox::warning(nullptr, "Фігура буде пропущена!", message.c_str());
        }
        figureCount++;
        if (figureCount == LIMIT_OF_FIGURES) break;
    }
    fclose(fp);
    repaint();
}

void MainWindow::on_figureChoice_activated(int index)
{
    SetVisibilityOfFields(false);
    switch(index + 1){
        case Square: {
            ui->l1->setText("Розмір сторін");
            ui->px1->setVisible(true);
            break;
        }
        case Rectangle:{
            ui->l1->setText("Ширина");
            ui->l2->setText("Висота");
            ui->l2->setVisible(true);
            ui->spin2->setVisible(true);
            ui->px1->setVisible(true);
            ui->px2->setVisible(true);
            break;
        }
        case Circle:{
            ui->l1->setText("Діаметр");
            ui->px1->setVisible(true);
            break;
        }
        case Triangle:{
            ui->l1->setText("Коорд. 1 т. x");
            ui->l2->setText("Коорд. 2 т. x");
            ui->l3->setText("Коорд. 3 т. x");
            ui->l2->setVisible(true);
            ui->l3->setVisible(true);
            ui->ly1->setVisible(true);
            ui->ly2->setVisible(true);
            ui->ly3->setVisible(true);
            ui->spin2->setVisible(true);
            ui->spin3->setVisible(true);
            ui->spinY1->setVisible(true);
            ui->spinY2->setVisible(true);
            ui->spinY3->setVisible(true);
            break;
        }
        case Ellipse:{
            ui->l1->setText("Ширина");
            ui->l2->setText("Висота");
            ui->l2->setVisible(true);
            ui->spin2->setVisible(true);
            ui->px1->setVisible(true);
            ui->px2->setVisible(true);
            break;
        }
    default:break;
    }
    ui->l1->setVisible(true);
    ui->spin1->setVisible(true);
    ui->pushDrawFromUI->setVisible(true);
    ui->pushCancelDraw->setVisible(true);
}

void MainWindow::on_pushDrawFromUI_clicked()
{
    int CurrentPositionToRepaint = ui->spinCurrCell->text().toInt() - 1;
    switch(ui->figureChoice->currentIndex()+1){
        case Square: {
            figures[CurrentPositionToRepaint].type = Square;
            FSquare *temp = new FSquare(figures[CurrentPositionToRepaint].position, ui->spin1->text().toInt());
            figures[CurrentPositionToRepaint].figure = temp;
            break;
        }
        case Rectangle:{
            try {
                if (ui->spin1->text().toInt() == ui->spin2->text().toInt())
                    throw "Прямокутник з одинаковою шириною та висотою є квадратом!";
            } catch(const char *message){
                QMessageBox::warning(nullptr, "Буде намальований квадрат!", message);
                figures[CurrentPositionToRepaint].type = Square;
                FSquare *temp = new FSquare(figures[CurrentPositionToRepaint].position, ui->spin1->text().toInt());
                figures[CurrentPositionToRepaint].figure = temp;
                break;
            }
            figures[CurrentPositionToRepaint].type = Rectangle;
            FRectangle *temp = new FRectangle(figures[CurrentPositionToRepaint].position, ui->spin1->text().toInt(), ui->spin2->text().toInt());
            figures[CurrentPositionToRepaint].figure = temp;
            break;
        }
        case Circle:{
            figures[CurrentPositionToRepaint].type = Circle;
            FCircle *temp = new FCircle(figures[CurrentPositionToRepaint].position, ui->spin1->text().toInt());
            figures[CurrentPositionToRepaint].figure = temp;
            break;
        }
        case Triangle:{
            Coordinates points[3];
            points[0].x = ui->spin1->text().toInt();
            points[0].y = ui->spinY1->text().toInt();
            points[1].x = ui->spin2->text().toInt();
            points[1].y = ui->spinY2->text().toInt();
            points[2].x = ui->spin3->text().toInt();
            points[2].y = ui->spinY3->text().toInt();
            try {
                if ((points[0].x == points[1].x && points[0].x == points[2].x) || (points[0].y == points[1].y && points[0].y == points[2].y)){
                    throw "Неможливо утворити трикутник з відрізків які знаходяться на одній прямій, змініть дані!";
                }
                if (((points[0].x == points[1].x) && (points[0].y == points[1].y)) || ((points[0].x == points[2].x) && (points[0].y == points[2].y)) || ((points[2].x == points[1].x) && (points[2].y == points[1].y))){
                    throw "Неможливо утворити трикутник, бо дві або три вершини знаходяться в одній точці, змініть дані!";
                }
            } catch(const char *message){
                QMessageBox::warning(nullptr, "Фігура не буде намальована", message);
                return;
            }
            figures[CurrentPositionToRepaint].type = Triangle;
            FTriangle *temp = new FTriangle(figures[CurrentPositionToRepaint].position, points[0], points[1], points[2]);
            figures[CurrentPositionToRepaint].figure = temp;
            break;
        }
        case Ellipse:{
            try {
                if (ui->spin1->text().toInt() == ui->spin2->text().toInt())
                    throw "Еліпс з одинаковою шириною та висотою є колом!";
            } catch(const char *message){
                QMessageBox::warning(nullptr, "Буде намальоване коло!", message);
                figures[CurrentPositionToRepaint].type = Circle;
                FCircle *temp = new FCircle(figures[CurrentPositionToRepaint].position, ui->spin1->text().toInt());
                figures[CurrentPositionToRepaint].figure = temp;
                break;
            }
            figures[CurrentPositionToRepaint].type = Ellipse;
            FEllipse *temp = new FEllipse(figures[CurrentPositionToRepaint].position, ui->spin1->text().toInt(), ui->spin2->text().toInt());
            figures[CurrentPositionToRepaint].figure = temp;
            break;
        }
    }
    figures[CurrentPositionToRepaint].color = ui->figureColor->currentIndex() + 1;
    repaint();
}


void MainWindow::on_pushSave_clicked()
{
    QString QFileName = QFileDialog :: getSaveFileName(this, "Save file as","D:\\2 course\\kursova\\option17\\newFigureInfo");
    int bCheck = 0;
    FILE *fp = fopen(QFileName.toUtf8().constData(), "w");
    if (!fp) return;
    for(int i = 0; i < LIMIT_OF_FIGURES; ++i){
        if (bCheck) {
            fprintf(fp, "\n");
        }
        bCheck = 1;
        switch(figures[i].type){
            case Square: {
                FSquare *temp = dynamic_cast<FSquare*>(figures[i].figure);
                fprintf(fp, "%d %d %d", figures[i].type, figures[i].color, temp->getSideSize());
                break;
            }
            case Rectangle:{
                FRectangle *temp = dynamic_cast<FRectangle*>(figures[i].figure);
                fprintf(fp, "%d %d %d %d", figures[i].type, figures[i].color, temp->getWidth(), temp->getHeight());
                break;
            }
            case Circle:{
                FCircle *temp = dynamic_cast<FCircle*>(figures[i].figure);
                fprintf(fp, "%d %d %d", figures[i].type, figures[i].color, temp->getDiameter());
                break;
            }
            case Triangle:{
                FTriangle *temp = dynamic_cast<FTriangle*>(figures[i].figure);
                fprintf(fp, "%d %d %d %d %d %d %d %d", figures[i].type, figures[i].color, (temp->getX1() - figures[i].position.x), (temp->getY1() - figures[i].position.y), (temp->getX2() - figures[i].position.x), (temp->getY2() - figures[i].position.y), (temp->getX3() - figures[i].position.x), (temp->getY3() - figures[i].position.y));
                break;
            }
            case Ellipse:{
                FEllipse *temp = dynamic_cast<FEllipse*>(figures[i].figure);
                fprintf(fp, "%d %d %d %d", figures[i].type, figures[i].color, temp->getWidth(), temp->getHeight());
                break;
            }
            default:{
                fprintf(fp, "%d %d %d", 0, 0, 0);
            }
        }
    }
    QMessageBox::information(nullptr, "Збереження файлу", "Файл було успішно збережено!");
    fclose(fp);
}

void MainWindow::on_pushCancelDraw_clicked()
{
    figures[ui->spinCurrCell->text().toInt() - 1].type = 0;
    figures[ui->spinCurrCell->text().toInt() - 1].figure = nullptr;
    labelForToolTip[ui->spinCurrCell->text().toInt() - 1]->setVisible(false);
    repaint();
}

void MainWindow::on_pushCancelAll_clicked()
{
    for (int i = 0; i < LIMIT_OF_FIGURES; ++i){
        figures[i].type = 0;
        figures[i].figure = nullptr;
        labelForToolTip[i]->setVisible(false);
    }
    repaint();
}

void MainWindow::on_pushOneColor_clicked()
{
    for (int i = 0; i < LIMIT_OF_FIGURES; ++i){
        figures[i].color = ui->figureColor->currentIndex()+1;
    }
    repaint();
}

void MainWindow::on_pushSingleColor_clicked()
{
    for (int i = 0; i < LIMIT_OF_FIGURES; ++i){
        switch(figures[i].type){
            case Square: {
                figures[i].color = Red;
                break;
            }
            case Rectangle:{
                figures[i].color = Blue;
                break;
            }
            case Circle:{
                figures[i].color = Purple;
                break;
            }
            case Triangle:{
                figures[i].color = Green;
                break;
            }
            case Ellipse:{
                figures[i].color = Black;
                break;
            }
            default:{

            }
        }
    }
    repaint();
}

MainWindow::~MainWindow()
{
    for (int i = 0; i < LIMIT_OF_FIGURES; ++i){
        delete figures[i].figure;
    }
    delete ui;
}
