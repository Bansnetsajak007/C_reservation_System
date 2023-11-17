const topdf = require('docx2pdf-converter')

const inputPath = './report.docx';

topdf.convert(inputPath,'output.pdf')