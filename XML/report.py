import pymysql
import json
import csv
import xml.etree.ElementTree as ET
import sys, datetime
from PyQt5.QtWidgets import *
from PyQt5.QtCore import Qt


class DB_Utils:

    def queryExecutor(self, db, sql, params):
        conn = pymysql.connect(host='localhost', user='guest', password='bemyguest', db=db, charset='utf8')
        try:
            with conn.cursor(pymysql.cursors.DictCursor) as cursor:     # dictionary based cursor
                cursor.execute(sql, params)
                tuples = cursor.fetchall()
                return tuples
        except Exception as e:
            print(e)
            print(type(e))
        finally:
            conn.close()

    def updateExecutor(self, db, sql, params):
        conn = pymysql.connect(host='localhost', user='guest', password='bemyguest', db=db, charset='utf8')

        try:
            with conn.cursor() as cursor:
                cursor.execute(sql, params)
            conn.commit()
        except Exception as e:
            print(e)
            print(type(e))
        finally:
            conn.close()

class DB_Query:
    # 모든 검색문은 여기에 각각 하나의 메소드로 정의

    # 팀명으로 검색하는 검색문
    def selectT(self, team):
        if team != '사용안함':
            # team_id를 이용해 team_name을 찾는다.
            sql = " JOIN team ON player.team_id = team.team_id WHERE team_name = '%s'" %(team)
        else:
            sql = ""
        return sql

    # 국적으로 검색하는 검색문
    def selectN(self, nation):
        if nation != '사용안함':
            if nation == '대한민국':
                sql = " nation IS NULL"
            else:
                sql = " nation = '%s'" %(nation)
        else:
            sql = ""

        return sql

    # 포지션으로 검색하는 검색문
    def selectP(self, position):
        if position != '사용안함':
            if position == '미정':
                sql = " position IS NULL"
            else:
                sql = " position = '%s'" %(position)
        else:
            sql = ""

        return sql

    # 키에 따른 검색문
    def selectH(self, height, bos):         # 키의 값과 이상,이하로 검색
        if height != '사용안함':
            if bos == '이상':
                sql = " height >= %s" %(height)
            else:
                sql = " height <= %s" %(height)
        else:
            sql = ""

        return sql

    # 몸무게에 따른 검색문
    def selectW(self, weight, bos2):        # 몸무게의 값과 이상,이하로 검색
        if weight != '사용안함':
            if bos2 == '이상':
                sql = " weight >= %s" %(weight)
            else:
                sql = " weight <= %s" %(weight)
        else:
            sql = ""
        return sql

    # 각각의 검색문을 합쳐서 하나의 검색문으로 만들어주는 함수
    def bind(self, team, nation, pos, height, weight):
        a = [team, nation, pos, height, weight]
        count = 0
        sql = "SELECT * FROM PLAYER"            #default 값 (전부 사용안함)
        # 함수의 파라미터를 하나의 질의문으로 만들기 위한 for 문
        for i in range(5):
            if a[i] != "":
                count = count+1
                if count == 1:
                    if i == 0:
                        sql = "SELECT PLAYER_ID,PLAYER_NAME,PLAYER.TEAM_ID, E_PLAYER_NAME, NICKNAME, JOIN_YYYY, POSITION, BACK_NO, NATION, BIRTH_DATE, SOLAR,HEIGHT,WEIGHT FROM PLAYER" + a[i]                # team이 사용안함이 아닌 경우
                    else:
                        sql = "SELECT * FROM player WHERE" + a[i]           # team이 사용안함인 경우
                elif count != 1 and count !=0:
                    sql = sql + " AND" +a[i]
        params = ()
        util = DB_Utils()
        tuples = util.queryExecutor(db="kleague", sql=sql, params=params)
        # 검색 결과가 아무것도 없는 경우 handling하는 if문
        if len(tuples) == 0:
            tuples = ("none")

        return tuples

    # combobox1의 값을 설정
    def selectTeam(self):
        sql = "SELECT DISTINCT team_name FROM team"
        params = ()

        util = DB_Utils()
        tuples = util.queryExecutor(db="kleague", sql=sql, params=params)
        return tuples

    # combobox2의 값을 설정
    def selectNations(self):
        sql = "SELECT DISTINCT nation FROM player"
        params = ()

        util = DB_Utils()
        tuples = util.queryExecutor(db="kleague", sql=sql, params=params)
        return tuples

    # combobox3의 값을 설정
    def selectPosition(self):
        sql = "SELECT DISTINCT position FROM player"
        params = ()
        util = DB_Utils()
        tuples = util.queryExecutor(db="kleague", sql=sql, params=params)
        return tuples

    # combobox4의 값을 설정
    def selectHeight(self):
        sql1 = "SELECT DISTINCT height FROM player WHERE HEIGHT IS NOT NULL ORDER BY height DESC LIMIT 1"
        sql2 = "SELECT DISTINCT height FROM player WHERE HEIGHT IS NOT NULL ORDER BY height ASC LIMIT 1"
        params1 = ()
        params2 = ()

        util = DB_Utils()
        tuples1 = util.queryExecutor(db="kleague", sql=sql1, params=params1)
        tuples2 = util.queryExecutor(db="kleague", sql=sql2, params=params2)
        tuples = list(range(tuples1[0]['height'], tuples2[0]['height']-1, -1))
        return tuples

    # combobox5의 값을 설정
    def selectWeight(self):
        sql1 = "SELECT DISTINCT weight FROM player WHERE weight IS NOT NULL ORDER BY weight DESC LIMIT 1"
        sql2 = "SELECT DISTINCT weight FROM player WHERE weight IS NOT NULL ORDER BY weight ASC LIMIT 1"
        params1 = ()
        params2 = ()

        util = DB_Utils()
        tuples1 = util.queryExecutor(db="kleague", sql=sql1, params=params1)
        tuples2 = util.queryExecutor(db="kleague", sql=sql2, params=params2)
        tuples = list(range(tuples1[0]['weight'], tuples2[0]['weight'] -1, -1))
        return tuples

#########################################

class MainWindow(QWidget):
    def __init__(self):
        super().__init__()
        self.setupUI()

    def setupUI(self):
        # 윈도우 설정
        self.setWindowTitle("Report")
        self.setGeometry(410, 130, 1100, 820)

        # 라벨 설정
        self.label1 = QLabel("팀명 :", self)
        self.label1.move(50, 30)
        self.label1.resize(100, 20)

        self.label2 = QLabel("국적 :", self)
        self.label2.move(280, 30)
        self.label2.resize(100, 20)

        self.label3 = QLabel("포지션 :", self)
        self.label3.move(510, 30)
        self.label3.resize(100, 20)

        self.label4 = QLabel("키 :", self)
        self.label4.move(50, 100)
        self.label4.resize(100, 20)

        self.label4 = QLabel("몸무게 :", self)
        self.label4.move(450, 100)
        self.label4.resize(100, 20)

        self.label5 = QLabel("파일명 : ", self)
        self.label5.move(50, 700)
        self.label5.resize(100, 20)

        # 라인에디트 설정
        self.lineEdit = QLineEdit( self)
        self.lineEdit.move(100, 698)
        self.lineEdit.resize(150,30)

        # 콤보박스 설정
        self.comboBox1 = QComboBox(self)
        self.comboBox2 = QComboBox(self)
        self.comboBox3 = QComboBox(self)
        self.comboBox4 = QComboBox(self)
        self.comboBox5 = QComboBox(self)

        # 라디오 버튼
        groupbox = QGroupBox("조건",self)
        groupbox.setAlignment(Qt.AlignHCenter)
        groupbox.move(215,83)
        groupbox.resize(130,45)
        self.radio1 = QRadioButton("이상", self)
        self.radio1.setChecked(True)
        self.radio1.clicked.connect(self.radio_Activated)
        self.radio2 = QRadioButton("이하", self)
        self.radio2.clicked.connect(self.radio_Activated)
        rbox = QHBoxLayout(self)
        rbox.addWidget(self.radio1)
        rbox.addWidget(self.radio2)
        groupbox.setLayout(rbox)

        groupbox2 = QGroupBox("조건", self)
        groupbox2.setAlignment(Qt.AlignHCenter)
        groupbox2.move(620, 83)
        groupbox2.resize(130, 45)
        self.radio3 = QRadioButton("이상", self)
        self.radio3.setChecked(True)
        self.radio3.clicked.connect(self.radio_Activated2)
        self.radio4 = QRadioButton("이하", self)
        self.radio4.clicked.connect(self.radio_Activated2)
        rbox2 = QHBoxLayout(self)
        rbox2.addWidget(self.radio3)
        rbox2.addWidget(self.radio4)
        groupbox2.setLayout(rbox2)

        groupbox3 = QGroupBox("파일 확장자명",self)
        groupbox3.move(300, 688)
        groupbox3.resize(300, 45)
        groupbox3.setAlignment(Qt.AlignHCenter)
        self.radio5 = QRadioButton("CSV",self)
        self.radio5.setChecked(True)
        self.radio5.clicked.connect(self.radio_Activated3)
        self.radio6 = QRadioButton("JSON", self)
        self.radio6.clicked.connect(self.radio_Activated3)
        self.radio7 = QRadioButton("XML", self)
        self.radio7.clicked.connect(self.radio_Activated3)
        rbox3 = QHBoxLayout(self)
        rbox3.addWidget(self.radio5)
        rbox3.addWidget(self.radio6)
        rbox3.addWidget(self.radio7)
        groupbox3.setLayout(rbox3)

        # 라디오 버튼에 따른 default 값들
        self.bigOrSmall = '이상'          # default 값
        self.bigOrSmall2 = '이상'         # default 값
        self.extend = 'CSV'              # default 값

        # DB 검색문 실행
        query = DB_Query()
        rows1 = query.selectTeam()                  # 팀
        rows2 = query.selectNations()               # 국적
        rows3 = query.selectPosition()              # 포지션
        rows4 = query.selectHeight()                # 키
        rows5 = query.selectWeight()                # 몸무게

        # combobox에 넣을 '사용안함' 값
        itemdefault = '사용안함'

        # combobox에 맞게 값들을 집어넣기
        self.comboBox1.insertItem(0, itemdefault)
        columnName = list(rows1[0].keys())[0]
        items = [row[columnName] for row in rows1]
        self.comboBox1.addItems(items)

        self.comboBox2.insertItem(0, itemdefault)
        columnName2 = list(rows2[0].keys())[0]
        items2 = ['대한민국' if row[columnName2] == None else row[columnName2] for row in rows2]
        self.comboBox2.addItems(items2)

        self.comboBox3.insertItem(0, itemdefault)
        columnName3 = list(rows3[0].keys())[0]
        items3 = ['미정' if row[columnName3] == None else row[columnName3] for row in rows3]
        self.comboBox3.addItems(items3)

        self.comboBox4.insertItem(0, itemdefault)
        items4 = [str(row) for row in rows4]
        self.comboBox4.addItems(items4)

        self.comboBox5.insertItem(0, itemdefault)
        items5 = [str(row) for row in rows5]
        self.comboBox5.addItems(items5)

        #combobox 설정
        self.comboBox1.move(90, 30)
        self.comboBox1.resize(150, 20)
        self.comboBox1.activated.connect(self.comboBox_Activated)

        self.comboBox2.move(330, 30)
        self.comboBox2.resize(130, 20)
        self.comboBox2.activated.connect(self.comboBox_Activated)

        self.comboBox3.move(560, 30)
        self.comboBox3.resize(100, 20)
        self.comboBox3.activated.connect(self.comboBox_Activated)

        self.comboBox4.move(90, 100)
        self.comboBox4.resize(100, 20)
        self.comboBox4.activated.connect(self.comboBox_Activated)

        self.comboBox5.move(500, 100)
        self.comboBox5.resize(100, 20)
        self.comboBox5.activated.connect(self.comboBox_Activated)

        # combobox에서 text 읽어오기
        self.teamName = self.comboBox1.currentText()
        self.nation = self.comboBox2.currentText()
        self.positionValue = self.comboBox3.currentText()
        self.height = self.comboBox4.currentText()
        self.weight = self.comboBox5.currentText()

        # 푸쉬버튼 설정
        self.pushButtonR = QPushButton("Refresh", self)
        self.pushButtonR.move(900, 25)
        self.pushButtonR.resize(100,30)
        self.pushButtonR.setStyleSheet("font: bold;"
                                       "border-style: solid;"
                                       "border-width: 2px;"
                                       "border-color: #000000;"
                                       "border-radius: 3px")
        self.pushButtonR.clicked.connect(self.pushButton_Refresh)

        self.pushButton = QPushButton("Search", self)
        self.pushButton.move(900, 95)
        self.pushButton.resize(100, 30)
        # Push button 차별화
        self.pushButton.setStyleSheet("font: bold;"
                                       "border-style: solid;"
                                       "border-width: 2px;"
                                       "border-color: #000000;"
                                       "border-radius: 3px")
        self.pushButton.clicked.connect(self.pushButton_Search)
        self.pushButtonS = QPushButton("Save", self)
        self.pushButtonS.move(900, 698)
        self.pushButtonS.resize(100, 30)
        #Push button 차별화
        self.pushButtonS.setStyleSheet("font: bold;"
                                       "border-style: solid;"
                                       "border-width: 2px;"
                                       "border-color: #000000;"
                                       "border-radius: 3px")
        self.pushButtonS.clicked.connect(self.pushButton_Save)

        # 테이블위젯 설정
        self.tableWidget = QTableWidget(self)   # QTableWidget 객체 생성
        self.tableWidget.move(50, 170)
        self.tableWidget.resize(1000, 500)

    # combobox 값 설정 함수
    def comboBox_Activated(self):
        self.teamName = self.comboBox1.currentText()            # teamName을 통해 선택한 팀명 값을 전달
        self.nation = self.comboBox2.currentText()              # nation을 통해 선택한 국적 값을 전달
        self.positionValue = self.comboBox3.currentText()       # positionValue를 통해 선택한 포지션 값을 전달
        self.height = self.comboBox4.currentText()              # height을 통해 선택한 키 값을 전달
        self.weight = self.comboBox5.currentText()              # weight을 통해 선택한 키 값을 전달

    # 키에서 이상,이하 값을 설정하는 라디오 버튼 함수
    def radio_Activated(self):
        if self.radio1.isChecked():
            self.bigOrSmall = self.radio1.text()
        elif self.radio2.isChecked():
            self.bigOrSmall = self.radio2.text()

    # 몸무게에서 이상,이하 값을 설정하는 라디오 버튼 함수
    def radio_Activated2(self):
        if self.radio3.isChecked():
            self.bigOrSmall2 = self.radio3.text()
        elif self.radio4.isChecked():
            self.bigOrSmall2 = self.radio4.text()

    # 저장하는 파일 확장자명을 설정하는 라디오 버튼 함수
    def radio_Activated3(self):
        if self.radio5.isChecked():
            self.extend = self.radio5.text()
        elif self.radio6.isChecked():
            self.extend = self.radio6.text()
        elif self.radio7.isChecked():
            self.extend = self.radio7.text()

    # 버튼을 누르면 초기화하는 함수
    def pushButton_Refresh(self):
        self.tableWidget.clear()
        self.tableWidget.setRowCount(0)
        self.tableWidget.setColumnCount(0)
        self.comboBox1.setCurrentIndex(0)
        self.comboBox2.setCurrentIndex(0)
        self.comboBox3.setCurrentIndex(0)
        self.comboBox4.setCurrentIndex(0)
        self.comboBox5.setCurrentIndex(0)
        self.radio1.setChecked(True)
        self.radio3.setChecked(True)
        self.teamName = self.comboBox1.currentText()
        self.nation = self.comboBox2.currentText()
        self.positionValue = self.comboBox3.currentText()
        self.height = self.comboBox4.currentText()
        self.weight = self.comboBox5.currentText()

    # 버튼을 누르면 검색하는 함수
    def pushButton_Search(self):
        # DB 검색문 실행
        query = DB_Query()

        info1 = query.selectT(self.teamName)
        info2 = query.selectN(self.nation)
        info3 = query.selectP(self.positionValue)
        info4 = query.selectH(self.height, self.bigOrSmall)
        info5 = query.selectW(self.weight, self.bigOrSmall2)

        self.players = query.bind(info1, info2, info3, info4, info5)

        # if문을 이용해 검색 결과가 없는 경우를 handling
        if self.players != 'none':
            self.tableWidget.clearContents()
            self.tableWidget.setRowCount(len(self.players))
            self.tableWidget.setColumnCount(len(self.players[0]))
            columnNames = list(self.players[0].keys())
            self.tableWidget.setHorizontalHeaderLabels(columnNames)
            self.tableWidget.setEditTriggers(QAbstractItemView.NoEditTriggers)

            for rowIDX in range(len(self.players)):
                player = self.players[rowIDX]
                for k, v in player.items():
                    columnIDX = columnNames.index(k)

                    if v == None:           # 파이썬이 DB의 널값을 None으로 변환함.
                        continue            # QTableWidgetItem 객체를 생성하지 않음
                    elif isinstance(v, datetime.date):      # QTableWidgetItem 객체 생성
                        item = QTableWidgetItem(v.strftime('%Y-%m-%d'))
                    else:
                        item = QTableWidgetItem(str(v))

                    self.tableWidget.setItem(rowIDX, columnIDX, item)

            self.tableWidget.resizeColumnsToContents()
            self.tableWidget.resizeRowsToContents()
        # 검색결과가 없으면 오류 메세지 박스를 출력
        else:
            print(self.players)
            QMessageBox.about(self, "오류", "검색결과가 없습니다.")

    # 버튼을 누르면 파일로 저장하는 함수
    def pushButton_Save(self):
        name = self.lineEdit.text()             # 파일명을 직접 정할 수 있게 한다.

        # 메시지 박스로 저장 의사를 물어봄
        msg = "저장하시겠습니까?"
        msg += "\n파일명 : " + name + "." + self.extend.lower()
        reply = QMessageBox.question(self, "저장", msg, QMessageBox.Yes | QMessageBox.No, QMessageBox.No)

        # 라디오 버튼에 따라 파일을 저장
        if reply == QMessageBox.Yes and self.extend == 'CSV':
            name += '.csv'
            self.writeCSV(self.players, name)
            QMessageBox.about(self,"저장","저장되었습니다.")
        elif reply == QMessageBox.Yes and self.extend == 'JSON':
            name += '.json'
            self.writeJSON(self.players, name)
            QMessageBox.about(self, "저장", "저장되었습니다.")
        elif reply == QMessageBox.Yes and self.extend == 'XML':
            name += '.xml'
            self.writeXML(self.players, name)
            QMessageBox.about(self, "저장", "저장되었습니다.")
        elif reply == QMessageBox.No:
            QMessageBox.about(self, "취소", "저장되지 않았습니다.")

    # JSON 파일로 저장
    def writeJSON(self, players, name):
        for player in players:
            for k, v in player.items():
                if isinstance(v, datetime.date):
                    player[k] = v.strftime('%Y-%m-%d')  # 키가 k인 item의 값 v를 수정

        newDict = dict(player = players)

        with open(name , 'w', encoding='utf-8') as f:
            json.dump(newDict, f, indent=4, ensure_ascii=False)

    # CSV 파일로 저장
    def writeCSV(self,players, name):
        with open(name , 'w', encoding='utf-8', newline='') as f:
            wr = csv.writer(f)
            columNames = list(players[0].keys())
            wr.writerow(columNames)

            for rowIDX in range(len(players)):
                row = list(players[rowIDX].values())
                wr.writerow(row)

    # XML 파일로 저장
    def writeXML(self,players, name):
        for player in players:
            for k, v in player.items():
                if isinstance(v, datetime.date):
                    player[k] = v.strftime('%Y-%m-%d')  # 키가 k인 item의 값 v를 수정

        newDict = dict(player = players)
        tableName = list(newDict.keys())[0]
        tableRows = list(newDict.values())[0]

        rootElement = ET.Element('TABLE')
        rootElement.attrib['name'] = tableName

        for row in tableRows:
            rowElement = ET.Element('ROW')
            rootElement.append(rowElement)

            for columnName in list(row.keys()):
                if row[columnName] == None:  # NICKNAME, JOIN_YYYY, NATION 처리
                    rowElement.attrib[columnName] = ''
                else:
                    rowElement.attrib[columnName] = row[columnName]

                if type(row[columnName]) == int:  # BACK_NO, HEIGHT, WEIGHT 처리
                    rowElement.attrib[columnName] = str(row[columnName])

        indent_a(rootElement)
        ET.ElementTree(rootElement).write(name, encoding='utf-8', xml_declaration=True)

#########################################

# XML 파일로 저장할 때 가시성을 높이기 위한 함수
def indent_a(elem, level = 0):
    indent = "\n" + level * "  "
    if len(elem):
        if not elem.text or not elem.text.strip():
            elem.text = indent + "  "
        if not elem.tail or not elem.tail.strip():
            elem.tail = indent
        for elem in elem:
            indent_a(elem, level+1)
        if not elem.tail or not elem.tail.strip():
            elem.tail = indent
    else:
        if level and (not elem.tail or not elem.tail.strip()):
            elem.tail = indent


def main():
    app = QApplication(sys.argv)
    mainWindow = MainWindow()
    mainWindow.show()
    sys.exit(app.exec_())

main()