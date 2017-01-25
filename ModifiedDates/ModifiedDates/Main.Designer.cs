namespace ModifiedDates
{
    partial class Main
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Main));
            this.extract_btn = new System.Windows.Forms.Button();
            this.src_btn = new System.Windows.Forms.Button();
            this.opt_btn = new System.Windows.Forms.Button();
            this.src_lbl = new System.Windows.Forms.Label();
            this.opt_lbl = new System.Windows.Forms.Label();
            this.progressBar1 = new System.Windows.Forms.ProgressBar();
            this.usage_lbl = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // extract_btn
            // 
            this.extract_btn.Location = new System.Drawing.Point(13, 247);
            this.extract_btn.Name = "extract_btn";
            this.extract_btn.Size = new System.Drawing.Size(75, 23);
            this.extract_btn.TabIndex = 0;
            this.extract_btn.Text = "Extract";
            this.extract_btn.UseVisualStyleBackColor = true;
            this.extract_btn.Click += new System.EventHandler(this.extract_btn_Click);
            // 
            // src_btn
            // 
            this.src_btn.Location = new System.Drawing.Point(12, 128);
            this.src_btn.Name = "src_btn";
            this.src_btn.Size = new System.Drawing.Size(98, 23);
            this.src_btn.TabIndex = 1;
            this.src_btn.Text = "Source Input";
            this.src_btn.UseVisualStyleBackColor = true;
            this.src_btn.Click += new System.EventHandler(this.src_btn_Click);
            // 
            // opt_btn
            // 
            this.opt_btn.Location = new System.Drawing.Point(13, 165);
            this.opt_btn.Name = "opt_btn";
            this.opt_btn.Size = new System.Drawing.Size(98, 23);
            this.opt_btn.TabIndex = 2;
            this.opt_btn.Text = "Output Location";
            this.opt_btn.UseVisualStyleBackColor = true;
            this.opt_btn.Click += new System.EventHandler(this.opt_btn_Click);
            // 
            // src_lbl
            // 
            this.src_lbl.AutoSize = true;
            this.src_lbl.Location = new System.Drawing.Point(124, 133);
            this.src_lbl.Name = "src_lbl";
            this.src_lbl.Size = new System.Drawing.Size(194, 13);
            this.src_lbl.TabIndex = 3;
            this.src_lbl.Text = "Select the folder to process for extration";
            // 
            // opt_lbl
            // 
            this.opt_lbl.AutoSize = true;
            this.opt_lbl.Location = new System.Drawing.Point(124, 170);
            this.opt_lbl.Name = "opt_lbl";
            this.opt_lbl.Size = new System.Drawing.Size(228, 13);
            this.opt_lbl.TabIndex = 4;
            this.opt_lbl.Text = "Select where would you like to save the output";
            // 
            // progressBar1
            // 
            this.progressBar1.Location = new System.Drawing.Point(127, 247);
            this.progressBar1.Name = "progressBar1";
            this.progressBar1.Size = new System.Drawing.Size(225, 23);
            this.progressBar1.TabIndex = 5;
            // 
            // usage_lbl
            // 
            this.usage_lbl.AutoEllipsis = true;
            this.usage_lbl.ForeColor = System.Drawing.Color.OrangeRed;
            this.usage_lbl.Location = new System.Drawing.Point(9, 9);
            this.usage_lbl.Name = "usage_lbl";
            this.usage_lbl.Size = new System.Drawing.Size(360, 96);
            this.usage_lbl.TabIndex = 6;
            this.usage_lbl.Text = resources.GetString("usage_lbl.Text");
            // 
            // Main
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(381, 289);
            this.Controls.Add(this.usage_lbl);
            this.Controls.Add(this.progressBar1);
            this.Controls.Add(this.opt_lbl);
            this.Controls.Add(this.src_lbl);
            this.Controls.Add(this.opt_btn);
            this.Controls.Add(this.src_btn);
            this.Controls.Add(this.extract_btn);
            this.Name = "Main";
            this.Text = "Modified Date Extractor";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button extract_btn;
        private System.Windows.Forms.Button src_btn;
        private System.Windows.Forms.Button opt_btn;
        private System.Windows.Forms.Label src_lbl;
        private System.Windows.Forms.Label opt_lbl;
        private System.Windows.Forms.ProgressBar progressBar1;
        private System.Windows.Forms.Label usage_lbl;
    }
}

