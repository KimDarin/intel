using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WinFormsTest03_Paint
{
    public partial class frmPaint : Form
    {
        Graphics g = null;
        Pen pen = null;
        Brush brush = null;

        int dMode = 0;  //0: Not, 1: Pen, 2: Line, 3: Rect, 4: Circle, 5: Text
        int dFlag = 0;  //0: Open, 1: pressed   (마우스 버튼)
        Point p1, p2, p3;
        public frmPaint()
        {
            InitializeComponent();
            g = Canvas.CreateGraphics();
            pen = new Pen(Color.Magenta, 2.0f);   //펜 색깔 베이지, 선 두께 1
            sbLabel4.Text = "";
        }

        private void Canvas_MouseDown(object sender, MouseEventArgs e)
        {
            dFlag = 1;  p1 = e.Location;
        }
        private void Canvas_MouseMove(object sender, MouseEventArgs e)  //현재 마우스의 좌표
        {
            string str = $"{e.X} x {e.Y}";
            sbLabel1.Text = str ;
            if (dFlag == 0) return;
            switch(dMode)
            {
                // pen draw mode
                case 1:
                    g.DrawLine(pen, p1, e.Location);
                    p1 = e.Location;
                    break;
                // Line draw mode 
                case 2:

                // Rect draw mode
                case 3:

                // Circle draw mode
                case 4:

                default:    break;

            }
        }
        private void Canvas_MouseUp(object sender, MouseEventArgs e)
        {
            dFlag = 0;
        }

        private void mnuDraw_Click(object sender, EventArgs e)
        {
            dMode = 1;  //연필 그리기
            sbLabel4.Text = "연필 그리기";
            sbLabel4.BackColor = Color.Aqua;
        }

        private void mnuLine_Click(object sender, EventArgs e)
        {
            dMode = 2;  //선 그리기
            sbLabel4.Text = "선 그리기";
            sbLabel4.BackColor = Color.Aqua;
        }

        private void mnuRect_Click(object sender, EventArgs e)
        {
            dMode = 3;  //사각형 그리기
            sbLabel4.Text = "사각형 그리기";
            sbLabel4.BackColor = Color.Aqua;
        }

        private void mnuCircle_Click(object sender, EventArgs e)
        {
            dMode = 4;  //원 그리기
            sbLabel4.Text = "원 그리기";
            sbLabel4.BackColor = Color.Aqua;
        }

        private void mnuText_Click(object sender, EventArgs e)
        {
            dMode = 5;  //문자 입력
            sbLabel4.Text = "문자 입력";
            sbLabel4.BackColor = Color.Aqua;
        }


        private void Canvas_Paint(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;
            Pen pen = new Pen(Color.Coral);

            Point p1 = new Point(Left, Top);
            Point p2 = new Point(Right, Bottom);
            Point p3 = new Point(Left, Bottom);
            Point p4 = new Point(Right, Top);

            g.DrawLine(pen, p1, p2);
            g.DrawLine(pen, p3, p4);
        }
    }
}
