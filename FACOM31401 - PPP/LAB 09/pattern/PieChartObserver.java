package observer.pattern;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.util.Vector;

import javax.swing.JPanel;

import observer.CourseRecord;
import observer.LayoutConstants;

public class PieChartObserver extends JPanel implements Observer {
   public PieChartObserver(CourseData data) {
       data.attach(this);
       this.courseData = data.getUpdate();
       this.setPreferredSize(new Dimension(2 * LayoutConstants.xOffset
               + (LayoutConstants.barSpacing + LayoutConstants.barWidth)
               * this.courseData.size(), LayoutConstants.graphHeight + 2
               * LayoutConstants.yOffset));
       this.setBackground(Color.white);
   }

   protected void paintComponent(Graphics g) {
       super.paintComponent(g);

       if (courseData == null || courseData.size() == 0)
           return;

       int radius = 100;

       Integer[] data = new Integer[courseData.size()];
       String[] labels = new String[courseData.size()];
       for (int i = 0; i < courseData.size(); i++) {
           CourseRecord rec = courseData.get(i);
           data[i] = rec.getNumOfStudents();
           labels[i] = rec.getName();
       }

       double total = 0.0;
       for (int num : data) {
           total += num;
       }

       if (total > 0) {
           double startAngle = 0.0;
           for (int i = 0; i < data.length; i++) {
               double ratio = (data[i] / total) * 360.0;
               g.setColor(LayoutConstants.courseColours[i % LayoutConstants.courseColours.length]);
               g.fillArc(LayoutConstants.xOffset, LayoutConstants.yOffset + 50,
                       2 * radius, 2 * radius,
                       (int) startAngle, (int) ratio);
               startAngle += ratio;
           }
       }

       int legendX = LayoutConstants.xOffset;
       int legendY = LayoutConstants.yOffset + 2 * radius + 70;
       int boxSize = 15;
       int spacing = 25;

       g.setColor(Color.black);
       g.drawString("Legenda:", legendX, legendY - 10);

       for (int i = 0; i < labels.length; i++) {
           g.setColor(LayoutConstants.courseColours[i % LayoutConstants.courseColours.length]);
           g.fillRect(legendX, legendY + i * spacing, boxSize, boxSize);

           g.setColor(Color.black);
           g.drawRect(legendX, legendY + i * spacing, boxSize, boxSize);
           g.drawString(labels[i], legendX + boxSize + 5, legendY + i * spacing + boxSize - 3);
       }
   }

   public void update(Observable o) {
       CourseData data = (CourseData) o;
       this.courseData = data.getUpdate();

       this.setPreferredSize(new Dimension(2 * LayoutConstants.xOffset
               + (LayoutConstants.barSpacing + LayoutConstants.barWidth)
               * this.courseData.size(), LayoutConstants.graphHeight + 2
               * LayoutConstants.yOffset));
       this.revalidate();
       this.repaint();
   }

   private Vector<CourseRecord> courseData;
}
