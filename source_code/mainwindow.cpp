#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    process=NULL;
    this->setAcceptDrops(true);
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(100);
    ui->progressBar->setValue(0);
    z=0;
    if(process==NULL)
        process=new Compression();
    //接受信号用于进度条
     connect(process,&Compression::mysigals,this,&MainWindow::display);

}

MainWindow::~MainWindow()
{
    delete ui;
    process->quit();
    if(process!=NULL)
        delete process;

}

//当用户拖动文件到窗口部件上时候，就会触发dragEnterEvent事件
void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    //如果为文件，则支持拖放
    if (event->mimeData()->hasFormat("text/uri-list"))
        event->acceptProposedAction();
}

//当用户放下这个文件后，就会触发dropEvent事件
void MainWindow::dropEvent(QDropEvent *event)
{

    QList<QUrl> urls = event->mimeData()->urls();
    if(urls.isEmpty())
        return;

    //往文本框中追加文件名
    foreach(QUrl url, urls) {
        QString file_name = url.toLocalFile();
        ui->lineEdit->setText(file_name);
        path=file_name;
    }
}
//进度条
void MainWindow::display()
{
    z++;
    ui->progressBar->setValue(z);
}

void MainWindow::on_openButton_clicked()
{
    path=QFileDialog::getOpenFileName(this,QString("选择文件"),QString("../.."),"All Files (*);;""Images (*.bmp);;""Text files (*.doc *.docx);;");
    ui->lineEdit->setText(path);
}

//压缩
void MainWindow::on_codeButton_clicked()
{
    ui->progressBar->setValue(0);
    z=0;
    process->MYpath=path;
    process->condition=coding;
    process->Filepath=Filepath;
    if(Filename.length()!=0){
        process->Filename=Filename;
    }
    else{
        process->Filename="";
    }
    process->start();
    qDebug()<<"开始压缩";
    QMessageBox::information(this,"warn","压缩成功 正在进行查重");
    on_checkButton_clicked(Filepath);
    ui->progressBar->setValue(0);
}

void MainWindow::on_decodeButton_2_clicked()
{
    QMessageBox::information(this,"warn","选择下载到的地址");
    QString filepath = QFileDialog::getExistingDirectory(this);
    ui->progressBar->setValue(0);
    z=0;
    process->condition=decoding;
    process->MYpath=path;
    process->Filepath=filepath;
    process->start();
    qDebug()<<"开始解压";
    QMessageBox::information(this,"warn","解压成功");
    ui->progressBar->setValue(0);
}

QStringList MainWindow::getFiles(const QString &path)
{
    QStringList ret;
    QDir dir(path);
    //QDir::Dirs碰到隐藏目录会报错,所以使用Dir::AllDirs
    QFileInfoList fileInfoList = dir.entryInfoList(QDir::Files|QDir::NoDotAndDotDot|QDir::Dirs);
    for(int i = 0; i <fileInfoList.count(); ++i){
        if(fileInfoList[i].isDir()){
            QStringList files = getFiles(fileInfoList[i].absoluteFilePath());
            ret.append(files);
        }
        else{
            ret.append(fileInfoList[i].absoluteFilePath());
        }
    }
    return ret;
}

QByteArray MainWindow::getFileMd5(const QString &fileName)
{
    QCryptographicHash hash(QCryptographicHash::Md5);
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox::information(this,"infomation","打开文件失败");
        return QByteArray();
    }
    while (!file.atEnd()) {
        QByteArray text = file.read(1024*10);
        hash.addData(text);
        qApp->processEvents();
    }

    QByteArray fileMd5 = hash.result();

    return fileMd5;
}

void MainWindow::on_checkButton_clicked(QString filepath)
{
    /*
    if(filepath.length()==0){
        filepath = QFileDialog::getExistingDirectory(this);
    }*/
    QVector<QString> vector;
    QVector<QString> fileall;
    //
      QStringList fileList =  getFiles(filepath);
      for(int i= 0; i < fileList.count(); i++){
          QString fileName = fileList.at(i);
          QByteArray md5 = getFileMd5(fileName);
          qDebug() << "fileName: "<<fileName <<" Md5:" << md5.toHex();
          fileMd5[md5].append(fileName);
          fileall.append(fileName);
      }
      for(int i=0;i<fileall.size();i++){
          for(int j=0;j<i;j++){
              QByteArray a1,a2;
              a1.append(fileall[i]);
              a2.append(fileall[j]);
              char *c1 = a1.data();
              char *c2 = a2.data();
              if(CompareMsg(c1,c2)==0){
                  QMessageBox::information(this,"有重复文件(全字符匹配查重)",fileall[i]+"&"+fileall[j]);
              }
          }
      }

      for(QHash<QByteArray, QStringList>::iterator it = fileMd5.begin();it!=fileMd5.end();++it){
          QString info = QString("Md5:%1\tcount:%2").arg(QString(it.key().toHex())).arg(it.value().count());
          ui->textEdit_show->append(info);
          if(it.value().count() >1){
              QMessageBox::information(this,"有重复文件(文件md5值查重)",it.value().first());
              vector.push_back(it.value().first());
          }
      }
      fileMd5.clear();
  //  return  vector*/
}

void MainWindow::on_checkButton_clicked()
{
    /*
    if(filepath.length()==0){

    }*/
    QString filepath = QFileDialog::getExistingDirectory(this);
    QVector<QString> fileall;
    QVector<QString> vector;
    //
      QStringList fileList =  getFiles(filepath);
      for(int i= 0; i < fileList.count(); i++){
          QString fileName = fileList.at(i);
            QByteArray md5 = getFileMd5(fileName);
            qDebug() << "fileName: "<<fileName <<" Md5:" << md5.toHex();
            fileMd5[md5].append(fileName);
            fileall.append(fileName);
      }
      for(int i=0;i<fileall.size();i++){
          for(int j=0;j<i;j++){
              QByteArray a1,a2;
              a1.append(fileall[i]);
              a2.append(fileall[j]);
              char *c1 = a1.data();
              char *c2 = a2.data();
              if(CompareMsg(c1,c2)==0){
                  QMessageBox::information(this,"有重复文件(全字符匹配查重)",fileall[i]+"&"+fileall[j]);
              }
          }
      }

      for(QHash<QByteArray, QStringList>::iterator it = fileMd5.begin();it!=fileMd5.end();++it){
          //QString info = QString("Md5:%1\tcount:%2").arg(QString(it.key().toHex())).arg(it.value().count());
          if(it.value().count() >1){
              QMessageBox::information(this,"有重复文件(文件md5值查重)",it.value().first());
              vector.push_back(it.value().first());
          }
      }
      fileMd5.clear();
  //  return  vector*/
}

int MainWindow::CompareMsg(char* msg1, char* msg2)
{
//将2个消息各自读取到buffer中
    FILE *pOne, *pTwe;
    long lsize1, lsize2;
    char* buffer1 = NULL;
    char* buffer2 = NULL;
    size_t result1, result2;

    pOne = fopen(msg1, "rb");
    pTwe = fopen(msg2, "rb");
    if ((pOne == NULL) || (pTwe == NULL))
    {
       fclose(pOne);
       fclose(pTwe);
      return 1;
    }

    fseek(pOne, 0, SEEK_END);
    lsize1 = ftell(pOne);
    //rewind(pOne);
    fseek(pOne, 0, SEEK_SET);
    fseek(pTwe, 0, SEEK_END);
    lsize2 = ftell(pTwe);
    rewind(pTwe);

    if (lsize1 != lsize2)
    {
       fclose(pOne);
       fclose(pTwe);
       return 1;
    }

    buffer1 = new char[lsize1];
    buffer2 = new char[lsize2];
    if ((buffer1 == NULL) || (buffer2 == NULL))
    {
       fclose(pOne);
       fclose(pTwe);
       delete[]buffer1;
       delete[]buffer2;
       return 1;
    }

    result1 = fread(buffer1, 1, lsize1, pOne);
    result2 = fread(buffer2, 1, lsize2, pTwe);
    if ((result1 != lsize1) || (result2 != lsize2))
    {
      fclose(pOne);
      fclose(pTwe);
      delete[]buffer1;
      delete[]buffer2;
      return 1;
    }


    int result = memcmp(buffer1, buffer2, lsize1);

    fclose(pOne);
    fclose(pTwe);
    delete[]buffer1;
    delete[]buffer2;

    return result;
}

void MainWindow::setFilepath(QString str)
{
   Filepath=str;
}

void MainWindow::setFilename(QString str)
{
   Filename=str;
}
