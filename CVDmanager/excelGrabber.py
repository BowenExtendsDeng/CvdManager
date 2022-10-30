from win32com.client import gencache
from openpyxl import load_workbook
import os
from configparser import ConfigParser
from shutil import move


class ExcelGrabber:

    def __init__(self, file_path):
        self.data = {'status': 200}
        self.file_path = file_path
        print(file_path)
        self.converter()
        self.writeData()

    def converter(self):
        excel = gencache.EnsureDispatch('Excel.Application')
        if not os.path.exists(self.file_path):
            self.data['status'] = 400
            return
        excel.Visible = False
        wb = excel.Workbooks.Open(self.file_path)
        if wb is None:
            self.data['status'] = 500
            return
        self.file_path = self.file_path + "x"

        if os.path.exists(self.file_path):
            os.remove(self.file_path)

        wb.SaveAs(self.file_path, FileFormat=51)
        wb.Close()
        excel.Application.Quit()
        self.readXlsx()

    def readXlsx(self):
        wb = load_workbook(self.file_path)
        sheet = wb['积分']
        methane = sheet['H43']
        self.data['methane'] = methane.value
        ethane = sheet['H44']
        self.data['ethane'] = ethane.value
        vinyl = sheet['H45']
        self.data['vinyl'] = vinyl.value
        propane = sheet['H46']
        self.data['propane'] = propane.value
        acetylene = sheet['H47']
        self.data['acetylene'] = acetylene.value

    def writeData(self):
        file = open("data.properties", "w")
        for key in self.data:
            num = str(self.data[key])
            file.write(key + "=" + num)
            file.write("\n")
        file.close()


if __name__ == '__main__':
    config = ConfigParser()
    config.read('config.ini')
    path = config.get('excel', 'file_path')
    move(path, "rsd-1.xls")
    path = os.path.abspath("rsd-1.xls")
    ExcelGrabber(path)
