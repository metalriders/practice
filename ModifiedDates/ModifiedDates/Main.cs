using iTextSharp.text.pdf;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ModifiedDates
{
    public partial class Main : Form
    {
        FolderBrowserDialog folderBrowserDialog1;
        SaveFileDialog saveFileDialog1;
        StreamWriter SaveFile;
        int no_files = 0, processed_files = 0;
        
        public Main()
        {
            InitializeComponent();

            progressBar1.Visible = true;
            progressBar1.Minimum = 1;
            progressBar1.Value = 1;
            progressBar1.Step = 1;
        }

        private void src_btn_Click(object sender, EventArgs e)
        {
            folderBrowserDialog1 = new System.Windows.Forms.FolderBrowserDialog();

            if (folderBrowserDialog1.ShowDialog() == DialogResult.OK)
                src_lbl.Text = folderBrowserDialog1.SelectedPath;
            else src_lbl.Text = "Select the folder to process for extration";
        }

        private void opt_btn_Click(object sender, EventArgs e)
        {
            saveFileDialog1 = new System.Windows.Forms.SaveFileDialog();
            saveFileDialog1.SupportMultiDottedExtensions = true;
            saveFileDialog1.DefaultExt = "txt";

            if (saveFileDialog1.ShowDialog() == DialogResult.OK)
                opt_lbl.Text = saveFileDialog1.FileName;
            else opt_lbl.Text = "Select where would you like to save the output";
        }

        private void extract_btn_Click(object sender, EventArgs e)
        {
            if (saveFileDialog1 == null || saveFileDialog1.FileName == "")
            {
                MessageBox.Show("Please select a file for output", "No output File selected", MessageBoxButtons.OK);
                return;
            }

            if (folderBrowserDialog1 == null || folderBrowserDialog1.SelectedPath == "")
            {
                MessageBox.Show("Please select a folder to process", "No input folder selected", MessageBoxButtons.OK);
                return;
            }

            // Create file to output file
            try
            {
                SaveFile = new System.IO.StreamWriter(saveFileDialog1.FileName);
            }
            catch (Exception)
            {

                MessageBox.Show("The following file was unable to open because it is being used by another process, close it then try again. \n File> " + saveFileDialog1.FileName, "Error");
                return;
            }

            // Get list of files from Src Path
            string[] files = Directory.GetFiles(src_lbl.Text);

            no_files = files.Length;
            processed_files = 0;
            progressBar1.Maximum = no_files;

            // For each PDF file get modified date and title of it and write into output file
            foreach (var file in files)
            {
                if (file.ToLower().Contains("pdf"))
                {
                    FileInfo fi = new FileInfo(file);
                    PdfReader reader = new PdfReader(file);

                    try
                    {
                        SaveFile.WriteLine(formatDate(reader.Info["CreationDate"]) + " :: " + formatDate(reader.Info["ModDate"]) + " :: " + fi.Name);
                    }
                    catch (Exception)
                    {
                        SaveFile.WriteLine(formatDate(reader.Info["CreationDate"]) + " :: " + formatDate(reader.Info["CreationDate"]) + " :: " + fi.Name);
                    }
                }

                processed_files++;
                updateProgressBar();
                
            }
            
            // close file
            SaveFile.Close();

            MessageBox.Show("Data extraction finished", "Operation Completed", MessageBoxButtons.OK);
            progressBar1.Value = 1;
        }

        private void updateProgressBar()
        {
            if(no_files > processed_files)
            {
                progressBar1.PerformStep();
            }
        }

        private string formatDate(string date)
        {
            string output = "";

            output = date.Substring(8, 2) + "/" + date.Substring(6, 2) + "/" + date.Substring(2, 4) + " " + date.Substring(10, 2) + ":" + date.Substring(12, 2) + ":" + date.Substring(14, 2);

            return output;
        }
    }
}
