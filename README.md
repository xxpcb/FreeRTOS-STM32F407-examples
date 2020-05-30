# 项目结构

## 库与工程模板

- **Template_lib** : STM32F407的库文件(v1.4.0)+FreeRTOS库文件(v9.0.0)
- **Template_noOS** : 基于Keil5.15的STM32F407模板工程(不包含操作系统)
- **Template_TreeRTOS** : 基于Keil5.15的STM32F407+FreeRTOS的模板工程

## 测试例程

- **001_FreeRTOS_LEDtask **: 任务创建实验，创建两个LED闪烁任务

# FreeRTOS文件结构

<!DOCTYPE html>
<!-- saved from url=(0016)http://localhost -->
<html>
  <head>
    <meta charset="utf-8"/>
    <meta content="IE=edge" http-equiv="X-UA-Compatible"/>
    <title>FreeRTOS v9.0.0.emmx</title>
    <style>
        body{
            margin: 0;
        }
        #content-info{
            width: auto;
            margin: 0 auto;
            text-align: center;
        }
        #author-info{
            white-space: nowrap;
            text-overflow: ellipsis;
            overflow: hidden;
        }
        #title{
            text-overflow: ellipsis;
            white-space: nowrap;
            overflow: hidden;
            padding-top: 10px;
            margin-bottom: 2px;
            font-size: 34px;
            color: #505050;
        }
        .text{
            white-space:nowrap;
            text-overflow: ellipsis;
            display: inline-block;
            margin-right: 20px;
            margin-bottom: 2px;
            font-size: 20px;
            color: #8c8c8c;
        }
        #navBar{
            width: auto;
            height: auto;
            position: fixed;
            right:0;
            bottom: 0;
            background-color: #f0f3f4;
            overflow-y: auto;
            text-align: center;
        }
        #svg-container{
            width: 100%;
            overflow-x: scroll;
            min-width: 0px;
            margin: 0 10px;
        }
        #nav-thumbs{
            overflow-y: scroll;
            padding: 0 5px;
        }
        .nav-thumb{
            position: relative;
            margin: 10px auto;
        }
        .nav-thumb >p{
            text-align: center;
            font-size: 12px;
            margin: 4px 0 0 0;
        }
        .nav-thumb >div{
            position: relative;
            display: inline-block;
            border: 1px solid #c6cfd5;
        }
        .nav-thumb img{
            display: block;
        }
        #main-content{
            bottom: 0;
            left: 0;
            right: 0;
            background-color: #d0cfd8;
            display: flex;
            height: auto;
            flex-flow: row wrap;
            text-align:center;
        }
        #svg-container >svg{
            display: block;
            margin:10px auto;
            margin-bottom: 0;
        }
        #copyright{
            bottom: 0;
            left: 50%;
            margin: 5px auto;
            font-size: 16px;
            color: #515151;
        }
        #copyright >a{
            text-decoration: none;
            color: #77C;
        }
        .number{
            position: absolute;
            top:0;
            left:0;
            border-top:22px solid #08a1ef;
            border-right: 22px solid transparent;
        }
        .pagenum{
            font-size: 12px;
            color: #fff;
            position: absolute;
            top: -23px;
            left: 2px;
        }
            #navBar::-webkit-scrollbar{
            width: 8px;
            background-color: #f5f5f5;
        }
            #navBar::-webkit-scrollbar-track{
            -webkit-box-shadow: inset 0 0 4px rgba(0,0,0,.3);
            border-radius: 8px;
            background-color: #fff;
        }
            #navBar::-webkit-scrollbar-thumb{
            border-radius: 8px;
            -webkit-box-shadow: inset 0 0 4px rgba(0,0,0,.3);
            background-color: #6b6b70;
        }
        #navBar::-webkit-scrollbar-thumb:hover{
            background-color: #4a4a4f;
        }
</style>
  </head>
  <body>
    <div id="main-area">
      <div id="main-content">
        <div id="svg-container"><svg height="1403" viewBox="0 0 1066 1403" id="page1" xmlns="http://www.w3.org/2000/svg" xmlns:ed="https://www.edrawsoft.com/xml/2017/SVGExtensions/" xmlns:ev="http://www.w3.org/2001/xml-events" ed:name="Page-1" ed:hSpacing="30" width="1066" xmlns:xlink="http://www.w3.org/1999/xlink" ed:vSpacing="30" preserveAspectRadio="xMinYMin meet">
    <style type="text/css"><![CDATA[
g[ed\:togtopicid],g[ed\:hyperlink],g[ed\:comment],g[ed\:note] {cursor:pointer;}
g[id] {-moz-user-select: none;-ms-user-select: none;user-select: none;}
svg text::selection,svg tspan::selection{background-color: #4285f4;color: #ffffff;fill: #ffffff;}
.st2 {fill:#303030;font-family:微软雅黑;font-size:12pt}
.st3 {fill:#454545;font-family:微软雅黑;font-size:10pt}
.st1 {fill:#ffffff;font-family:微软雅黑;font-size:12pt}
]]></style>
    <defs>
        <linearGradient y2="100%" x1="0%" id="lg1" y1="0%" x2="0%">
            <stop stop-color="#ffffff" offset="0"/>
            <stop stop-color="#f0f5f0" offset="0.25"/>
            <stop stop-color="#e1ebe1" offset="0.75"/>
            <stop stop-color="#c8d7c8" offset="1"/>
        </linearGradient>
    </defs>
    <rect height="1403" fill="#ffffff" x="0" y="0" width="1066"/>
    <path stroke="#696969" ed:parentid="101" fill="#696969" d="M-1.6,23.9C-2.7,23.8,-3.4,24.6,-3.4,25.4C-3.4,26.2,-2.7,27,-1.6,26.9L26.1,24.8L26.3,-24.9L61.3,-25.4L26.3,-25.9L23.8,24.8L-1.6,23.9z" id="103" transform="matrix(1,0,0,1,271,676.3)" stroke-linecap="round" ed:tosuperid="102" stroke-linejoin="round"/>
    <path stroke="#696969" ed:parentid="101" fill="#696969" d="M-1.6,-263.2C-2.7,-263.3,-3.4,-262.5,-3.4,-261.7C-3.4,-260.9,-2.7,-260.2,-1.6,-260.2L23.5,-261.1L26,261.8L61.3,261.7L26,261.6L26.4,-261.1L-1.6,-263.2z" id="108" transform="matrix(1,0,0,1,271,963.4)" stroke-linecap="round" ed:tosuperid="107" stroke-linejoin="round"/>
    <path stroke="#696969" ed:parentid="107" d="M-14.5,2.2C-2.4,2.2,4.6,-2.2,14.5,-2.2" fill="none" id="112" transform="matrix(1,0,0,1,497.9,1223)" stroke-linecap="round" ed:tosuperid="111" stroke-linejoin="round"/>
    <path stroke="#696969" ed:parentid="107" d="M-14.5,-14.1C0.3,-14.1,-1.8,14.1,14.5,14.1" fill="none" id="114" transform="matrix(1,0,0,1,497.9,1239.3)" stroke-linecap="round" ed:tosuperid="113" stroke-linejoin="round"/>
    <path stroke="#696969" ed:parentid="102" d="M-14.5,214.1C5.8,214.1,-14.5,-214.1,14.5,-214.1" fill="none" id="122" transform="matrix(1,0,0,1,460.3,436.9)" stroke-linecap="round" ed:tosuperid="121" stroke-linejoin="round"/>
    <path stroke="#696969" ed:parentid="102" d="M-14.5,173.3C5.8,173.3,-14.5,-173.3,14.5,-173.3" fill="none" id="124" transform="matrix(1,0,0,1,460.3,477.6)" stroke-linecap="round" ed:tosuperid="123" stroke-linejoin="round"/>
    <path stroke="#696969" ed:parentid="102" d="M-14.5,-46.7C5.4,-46.7,-13.6,46.7,14.5,46.7" fill="none" id="126" transform="matrix(1,0,0,1,460.3,697.7)" stroke-linecap="round" ed:tosuperid="125" stroke-linejoin="round"/>
    <path stroke="#696969" ed:parentid="125" d="M-14.5,97.8C5.8,97.8,-14.5,-97.8,14.5,-97.8" fill="none" id="130" transform="matrix(1,0,0,1,536.5,646.6)" stroke-linecap="round" ed:tosuperid="129" stroke-linejoin="round"/>
    <path stroke="#696969" ed:parentid="125" d="M-14.5,-65.2C5.8,-65.2,-14.5,65.2,14.5,65.2" fill="none" id="132" transform="matrix(1,0,0,1,536.5,809.6)" stroke-linecap="round" ed:tosuperid="131" stroke-linejoin="round"/>
    <path stroke="#696969" ed:parentid="125" d="M-14.5,-122.3C5.8,-122.3,-14.5,122.3,14.5,122.3" fill="none" id="134" transform="matrix(1,0,0,1,536.5,866.7)" stroke-linecap="round" ed:tosuperid="133" stroke-linejoin="round"/>
    <path stroke="#696969" ed:parentid="125" d="M-14.5,-138.5C5.8,-138.5,-14.5,138.5,14.5,138.5" fill="none" id="136" transform="matrix(1,0,0,1,536.5,883)" stroke-linecap="round" ed:tosuperid="135" stroke-linejoin="round"/>
    <path stroke="#696969" ed:parentid="125" d="M-14.5,-154.8C5.8,-154.8,-14.5,154.8,14.5,154.8" fill="none" id="138" transform="matrix(1,0,0,1,536.5,899.3)" stroke-linecap="round" ed:tosuperid="137" stroke-linejoin="round"/>
    <path stroke="#696969" ed:parentid="125" d="M-14.5,-171.1C5.8,-171.1,-14.5,171.1,14.5,171.1" fill="none" id="140" transform="matrix(1,0,0,1,536.5,915.5)" stroke-linecap="round" ed:tosuperid="139" stroke-linejoin="round"/>
    <path stroke="#696969" ed:parentid="125" d="M-14.5,-187.4C5.8,-187.4,-14.5,187.4,14.5,187.4" fill="none" id="142" transform="matrix(1,0,0,1,536.5,931.8)" stroke-linecap="round" ed:tosuperid="141" stroke-linejoin="round"/>
    <path stroke="#696969" ed:parentid="125" d="M-14.5,-203.7C5.8,-203.7,-14.5,203.7,14.5,203.7" fill="none" id="144" transform="matrix(1,0,0,1,536.5,948.1)" stroke-linecap="round" ed:tosuperid="143" stroke-linejoin="round"/>
    <path stroke="#696969" ed:parentid="129" d="M-14.5,106C5.8,106,-14.5,-106,14.5,-106" fill="none" id="146" transform="matrix(1,0,0,1,617.5,442.9)" stroke-linecap="round" ed:tosuperid="145" stroke-linejoin="round"/>
    <path stroke="#696969" ed:parentid="129" d="M-14.5,89.7C5.8,89.7,-14.5,-89.6,14.5,-89.6" fill="none" id="148" transform="matrix(1,0,0,1,617.5,459.2)" stroke-linecap="round" ed:tosuperid="147" stroke-linejoin="round"/>
    <path stroke="#696969" ed:parentid="129" d="M-14.5,73.4C5.8,73.4,-14.5,-73.4,14.5,-73.4" fill="none" id="150" transform="matrix(1,0,0,1,617.5,475.5)" stroke-linecap="round" ed:tosuperid="149" stroke-linejoin="round"/>
    <path stroke="#696969" ed:parentid="129" d="M-14.5,57C5.8,57,-14.5,-57.1,14.5,-57.1" fill="none" id="152" transform="matrix(1,0,0,1,617.5,491.8)" stroke-linecap="round" ed:tosuperid="151" stroke-linejoin="round"/>
    <path stroke="#696969" ed:parentid="129" d="M-14.5,40.8C4.9,40.8,-12.3,-40.8,14.5,-40.8" fill="none" id="154" transform="matrix(1,0,0,1,617.5,508.1)" stroke-linecap="round" ed:tosuperid="153" stroke-linejoin="round"/>
    <path stroke="#696969" ed:parentid="129" d="M-14.5,24.5C2.4,24.5,-6.7,-24.4,14.5,-24.4" fill="none" id="156" transform="matrix(1,0,0,1,617.5,524.4)" stroke-linecap="round" ed:tosuperid="155" stroke-linejoin="round"/>
    <path stroke="#696969" ed:parentid="129" d="M-14.5,8.1C-1,8.1,1.4,-8.2,14.5,-8.2" fill="none" id="158" transform="matrix(1,0,0,1,617.5,540.7)" stroke-linecap="round" ed:tosuperid="157" stroke-linejoin="round"/>
    <path stroke="#696969" ed:parentid="129" d="M-14.5,-8.1C-1,-8.1,1.4,8.2,14.5,8.2" fill="none" id="160" transform="matrix(1,0,0,1,617.5,557)" stroke-linecap="round" ed:tosuperid="159" stroke-linejoin="round"/>
    <path stroke="#696969" ed:parentid="129" d="M-14.5,-24.5C2.4,-24.5,-6.7,24.4,14.5,24.4" fill="none" id="162" transform="matrix(1,0,0,1,617.5,573.3)" stroke-linecap="round" ed:tosuperid="161" stroke-linejoin="round"/>
    <path stroke="#696969" ed:parentid="129" d="M-14.5,-40.7C4.9,-40.7,-12.3,40.8,14.5,40.8" fill="none" id="164" transform="matrix(1,0,0,1,617.5,589.5)" stroke-linecap="round" ed:tosuperid="163" stroke-linejoin="round"/>
    <path stroke="#696969" ed:parentid="129" d="M-14.5,-57C5.8,-57,-14.5,57,14.5,57" fill="none" id="166" transform="matrix(1,0,0,1,617.5,605.9)" stroke-linecap="round" ed:tosuperid="165" stroke-linejoin="round"/>
    <path stroke="#696969" ed:parentid="129" d="M-14.5,-73.3C5.8,-73.3,-14.5,73.3,14.5,73.3" fill="none" id="168" transform="matrix(1,0,0,1,617.5,622.1)" stroke-linecap="round" ed:tosuperid="167" stroke-linejoin="round"/>
    <path stroke="#696969" ed:parentid="129" d="M-14.5,-89.6C5.8,-89.6,-14.5,89.6,14.5,89.6" fill="none" id="170" transform="matrix(1,0,0,1,617.5,638.5)" stroke-linecap="round" ed:tosuperid="169" stroke-linejoin="round"/>
    <path stroke="#696969" ed:parentid="129" d="M-14.5,-105.9C5.8,-105.9,-14.5,105.9,14.5,105.9" fill="none" id="172" transform="matrix(1,0,0,1,617.5,654.7)" stroke-linecap="round" ed:tosuperid="171" stroke-linejoin="round"/>
    <path stroke="#696969" ed:parentid="121" d="M-14.5,24.5C2.4,24.5,-6.7,-24.4,14.5,-24.4" fill="none" id="174" transform="matrix(1,0,0,1,533.3,198.3)" stroke-linecap="round" ed:tosuperid="173" stroke-linejoin="round"/>
    <path stroke="#696969" ed:parentid="121" d="M-14.5,0C-2.9,0,5.8,0,14.5,0" fill="none" id="176" transform="matrix(1,0,0,1,533.3,222.8)" stroke-linecap="round" ed:tosuperid="175" stroke-linejoin="round"/>
    <path stroke="#696969" ed:parentid="121" d="M-14.5,-24.5C2.4,-24.5,-6.7,24.4,14.5,24.4" fill="none" id="178" transform="matrix(1,0,0,1,533.3,247.3)" stroke-linecap="round" ed:tosuperid="177" stroke-linejoin="round"/>
    <path stroke="#696969" ed:parentid="131" d="M-14.5,40.8C4.9,40.8,-12.3,-40.8,14.5,-40.8" fill="none" id="180" transform="matrix(1,0,0,1,624.7,834.1)" stroke-linecap="round" ed:tosuperid="179" stroke-linejoin="round"/>
    <path stroke="#696969" ed:parentid="131" d="M-14.5,8.2C-1,8.2,1.4,-8.2,14.5,-8.2" fill="none" id="182" transform="matrix(1,0,0,1,624.7,866.7)" stroke-linecap="round" ed:tosuperid="181" stroke-linejoin="round"/>
    <path stroke="#696969" ed:parentid="131" d="M-14.5,-32.6C3.8,-32.6,-9.9,32.6,14.5,32.6" fill="none" id="184" transform="matrix(1,0,0,1,624.7,907.4)" stroke-linecap="round" ed:tosuperid="183" stroke-linejoin="round"/>
    <path stroke="#696969" ed:parentid="183" d="M-14.5,8.1C-1,8.1,1.4,-8.2,14.5,-8.2" fill="none" id="186" transform="matrix(1,0,0,1,729.7,931.9)" stroke-linecap="round" ed:tosuperid="185" stroke-linejoin="round"/>
    <path stroke="#696969" ed:parentid="183" d="M-14.5,-8.1C-1,-8.1,1.4,8.2,14.5,8.2" fill="none" id="188" transform="matrix(1,0,0,1,729.7,948.1)" stroke-linecap="round" ed:tosuperid="187" stroke-linejoin="round"/>
    <path stroke="#696969" ed:parentid="181" d="M-14.5,8.1C-1,8.1,1.4,-8.2,14.5,-8.2" fill="none" id="190" transform="matrix(1,0,0,1,694.5,850.4)" stroke-linecap="round" ed:tosuperid="189" stroke-linejoin="round"/>
    <path stroke="#696969" ed:parentid="181" d="M-14.5,-16.3C0.8,-16.3,-2.9,16.3,14.5,16.3" fill="none" id="192" transform="matrix(1,0,0,1,694.5,874.8)" stroke-linecap="round" ed:tosuperid="191" stroke-linejoin="round"/>
    <path stroke="#696969" ed:parentid="189" d="M-14.5,8.2C-1,8.2,1.4,-8.1,14.5,-8.1" fill="none" id="194" transform="matrix(1,0,0,1,803.5,834)" stroke-linecap="round" ed:tosuperid="193" stroke-linejoin="round"/>
    <path stroke="#696969" ed:parentid="189" d="M-14.5,-8.2C-1,-8.2,1.4,8.1,14.5,8.1" fill="none" id="196" transform="matrix(1,0,0,1,803.5,850.4)" stroke-linecap="round" ed:tosuperid="195" stroke-linejoin="round"/>
    <path stroke="#696969" ed:parentid="179" d="M-14.5,0C-2.9,0,5.8,0,14.5,0" fill="none" id="198" transform="matrix(1,0,0,1,682.5,793.3)" stroke-linecap="round" ed:tosuperid="197" stroke-linejoin="round"/>
    <path stroke="#696969" ed:parentid="175" d="M-14.5,8.1C-1,8.1,1.4,-8.1,14.5,-8.1" fill="none" id="200" transform="matrix(1,0,0,1,779.1,214.6)" stroke-linecap="round" ed:tosuperid="199" stroke-linejoin="round"/>
    <path stroke="#696969" ed:parentid="175" d="M-14.5,-8.2C-1,-8.2,1.4,8.1,14.5,8.1" fill="none" id="202" transform="matrix(1,0,0,1,779.1,231)" stroke-linecap="round" ed:tosuperid="201" stroke-linejoin="round"/>
    <g ed:width="119.4" id="101" ed:layout="rightmap" transform="matrix(1,0,0,1,150,662.1)" ed:topictype="mainidea" ed:height="79.2">
        <path stroke="#435fbc" fill="#435fbc" d="M4,0L115.4,0C117.6,0,119.4,1.8,119.4,4L119.4,75.2C119.4,77.4,117.6,79.2,115.4,79.2L4,79.2C1.8,79.2,0,77.4,0,75.2L0,4C0,1.8,1.8,0,4,0z" stroke-width="3" stroke-linejoin="round"/>
        <text class="st1">
            <tspan style="white-space:pre" x="23" y="33">FreeRTOS</tspan>
            <tspan style="white-space:pre" x="35" y="55"> v9.0.0</tspan>
        </text>
    </g>
    <g ed:parentid="101" ed:width="113.4" id="102" transform="matrix(1,0,0,1,332.4,631.2)" ed:height="39.6">
        <path stroke="#ebecf3" fill="#ebecf3" d="M4,0L109.4,0C111.6,0,113.4,1.8,113.4,4L113.4,35.6C113.4,37.8,111.6,39.6,109.4,39.6L4,39.6C1.8,39.6,0,37.8,0,35.6L0,4C0,1.8,1.8,0,4,0z" stroke-linejoin="round"/>
        <text class="st2">
            <tspan style="white-space:pre" x="19" y="24">FreeRTOS</tspan>
        </text>
    </g>
    <g ed:parentid="101" ed:width="151" id="107" transform="matrix(1,0,0,1,332.4,1205.4)" ed:height="39.6">
        <path stroke="#ebecf3" fill="#ebecf3" d="M4,0L147,0C149.2,0,151,1.8,151,4L151,35.6C151,37.8,149.2,39.6,147,39.6L4,39.6C1.8,39.6,0,37.8,0,35.6L0,4C0,1.8,1.8,0,4,0z" stroke-linejoin="round"/>
        <text class="st2">
            <tspan style="white-space:pre" x="19" y="24">FreeRTOS-Plus</tspan>
        </text>
    </g>
    <g ed:parentid="107" ed:width="44" id="111" transform="matrix(1,0,0,1,512.4,1196.9)" ed:height="23.9">
        <path stroke="#696969" d="M0,23.9L44,23.9" fill="none" stroke-linejoin="round"/>
        <text class="st3">
            <tspan style="white-space:pre" x="1" y="15">Demo</tspan>
        </text>
    </g>
    <g ed:parentid="107" ed:width="48.8" id="113" transform="matrix(1,0,0,1,512.4,1229.5)" ed:height="23.9">
        <path stroke="#696969" d="M0,23.9L48.8,23.9" fill="none" stroke-linejoin="round"/>
        <text class="st3">
            <tspan style="white-space:pre" x="1" y="15">Source</tspan>
        </text>
    </g>
    <g ed:parentid="102" ed:width="44" id="121" transform="matrix(1,0,0,1,474.8,198.9)" ed:height="23.9">
        <path stroke="#696969" d="M0,23.9L44,23.9" fill="none" stroke-linejoin="round"/>
        <text class="st3">
            <tspan style="white-space:pre" x="1" y="15">Demo</tspan>
        </text>
    </g>
    <g ed:parentid="102" ed:width="52.8" id="123" transform="matrix(1,0,0,1,474.8,280.4)" ed:height="23.9">
        <path stroke="#696969" d="M0,23.9L52.8,23.9" fill="none" stroke-linejoin="round"/>
        <text class="st3">
            <tspan style="white-space:pre" x="1" y="15">License</tspan>
        </text>
    </g>
    <g ed:parentid="102" ed:width="47.2" id="125" transform="matrix(1,0,0,1,474.8,720.5)" ed:height="23.9">
        <path stroke="#696969" d="M0,23.9L47.2,23.9" fill="none" stroke-linejoin="round"/>
        <text class="st3">
            <tspan style="white-space:pre" x="1" y="15">source</tspan>
        </text>
    </g>
    <g ed:parentid="125" ed:width="52" id="129" transform="matrix(1,0,0,1,551,524.9)" ed:height="23.9">
        <path stroke="#696969" d="M0,23.9L52,23.9" fill="none" stroke-linejoin="round"/>
        <text class="st3">
            <tspan style="white-space:pre" x="1" y="15">include</tspan>
        </text>
    </g>
    <g ed:parentid="125" ed:width="59.2" id="131" transform="matrix(1,0,0,1,551,850.9)" ed:height="23.9">
        <path stroke="#696969" d="M0,23.9L59.2,23.9" fill="none" stroke-linejoin="round"/>
        <text class="st3">
            <tspan style="white-space:pre" x="1" y="15">portable</tspan>
        </text>
    </g>
    <g ed:parentid="125" ed:width="68" id="133" transform="matrix(1,0,0,1,551,965)" ed:height="23.9">
        <path fill="#4dc7bc" d="M0,0L68,0L68,23.9L0,23.9L0,0z"/>
        <path stroke="#696969" d="M0,23.9L68,23.9" fill="none" stroke-linejoin="round"/>
        <text class="st3">
            <tspan style="white-space:pre" x="1" y="15">croutine.c</tspan>
        </text>
    </g>
    <g ed:parentid="125" ed:width="102.4" id="135" transform="matrix(1,0,0,1,551,997.6)" ed:height="23.9">
        <path fill="#4dc7bc" d="M0,0L102.4,0L102.4,23.9L0,23.9L0,0z"/>
        <path stroke="#696969" d="M0,23.9L102.4,23.9" fill="none" stroke-linejoin="round"/>
        <text class="st3">
            <tspan style="white-space:pre" x="1" y="15">event_groups.c</tspan>
        </text>
    </g>
    <g ed:parentid="125" ed:width="33.59999999999999" id="137" transform="matrix(1,0,0,1,551,1030.2)" ed:height="23.9">
        <path fill="#4dc7bc" d="M0,0L33.6,0L33.6,23.9L0,23.9L0,0z"/>
        <path stroke="#696969" d="M0,23.9L33.6,23.9" fill="none" stroke-linejoin="round"/>
        <text class="st3">
            <tspan style="white-space:pre" x="1" y="15">list.c</tspan>
        </text>
    </g>
    <g ed:parentid="125" ed:width="55.2" id="139" transform="matrix(1,0,0,1,551,1062.8)" ed:height="23.9">
        <path fill="#4dc7bc" d="M0,0L55.2,0L55.2,23.9L0,23.9L0,0z"/>
        <path stroke="#696969" d="M0,23.9L55.2,23.9" fill="none" stroke-linejoin="round"/>
        <text class="st3">
            <tspan style="white-space:pre" x="1" y="15">queue.c</tspan>
        </text>
    </g>
    <g ed:parentid="125" ed:width="46.40000000000001" id="141" transform="matrix(1,0,0,1,551,1095.4)" ed:height="23.9">
        <path fill="#4dc7bc" d="M0,0L46.4,0L46.4,23.9L0,23.9L0,0z"/>
        <path stroke="#696969" d="M0,23.9L46.4,23.9" fill="none" stroke-linejoin="round"/>
        <text class="st3">
            <tspan style="white-space:pre" x="1" y="15">tasks.c</tspan>
        </text>
    </g>
    <g ed:parentid="125" ed:width="55.2" id="143" transform="matrix(1,0,0,1,551,1128)" ed:height="23.9">
        <path fill="#4dc7bc" d="M0,0L55.2,0L55.2,23.9L0,23.9L0,0z"/>
        <path stroke="#696969" d="M0,23.9L55.2,23.9" fill="none" stroke-linejoin="round"/>
        <text class="st3">
            <tspan style="white-space:pre" x="1" y="15">timers.c</tspan>
        </text>
    </g>
    <g ed:parentid="129" ed:width="68.8" id="145" transform="matrix(1,0,0,1,632,313)" ed:height="23.9">
        <path fill="#fceae9" d="M0,0L68.8,0L68.8,23.9L0,23.9L0,0z"/>
        <path stroke="#696969" d="M0,23.9L68.8,23.9" fill="none" stroke-linejoin="round"/>
        <text class="st3">
            <tspan style="white-space:pre" x="1" y="15">croutine.h</tspan>
        </text>
    </g>
    <g ed:parentid="129" ed:width="165.6" id="147" transform="matrix(1,0,0,1,632,345.6)" ed:height="23.9">
        <path fill="#fceae9" d="M0,0L165.6,0L165.6,23.9L0,23.9L0,0z"/>
        <path stroke="#696969" d="M0,23.9L165.6,23.9" fill="none" stroke-linejoin="round"/>
        <text class="st3">
            <tspan style="white-space:pre" x="1" y="15">deprecated_definitions.h</tspan>
        </text>
    </g>
    <g ed:parentid="129" ed:width="103.2" id="149" transform="matrix(1,0,0,1,632,378.2)" ed:height="23.9">
        <path fill="#fceae9" d="M0,0L103.2,0L103.2,23.9L0,23.9L0,0z"/>
        <path stroke="#696969" d="M0,23.9L103.2,23.9" fill="none" stroke-linejoin="round"/>
        <text class="st3">
            <tspan style="white-space:pre" x="1" y="15">event_groups.h</tspan>
        </text>
    </g>
    <g ed:parentid="129" ed:width="79.2" id="151" transform="matrix(1,0,0,1,632,410.8)" ed:height="23.9">
        <path fill="#fceae9" d="M0,0L79.2,0L79.2,23.9L0,23.9L0,0z"/>
        <path stroke="#696969" d="M0,23.9L79.2,23.9" fill="none" stroke-linejoin="round"/>
        <text class="st3">
            <tspan style="white-space:pre" x="1" y="15">FreeRTOS.h</tspan>
        </text>
    </g>
    <g ed:parentid="129" ed:width="34.40000000000001" id="153" transform="matrix(1,0,0,1,632,443.4)" ed:height="23.9">
        <path fill="#fceae9" d="M0,0L34.4,0L34.4,23.9L0,23.9L0,0z"/>
        <path stroke="#696969" d="M0,23.9L34.4,23.9" fill="none" stroke-linejoin="round"/>
        <text class="st3">
            <tspan style="white-space:pre" x="1" y="15">list.h</tspan>
        </text>
    </g>
    <g ed:parentid="129" ed:width="122.4" id="155" transform="matrix(1,0,0,1,632,476)" ed:height="23.9">
        <path fill="#fceae9" d="M0,0L122.4,0L122.4,23.9L0,23.9L0,0z"/>
        <path stroke="#696969" d="M0,23.9L122.4,23.9" fill="none" stroke-linejoin="round"/>
        <text class="st3">
            <tspan style="white-space:pre" x="1" y="15">mpu_prototypes.h</tspan>
        </text>
    </g>
    <g ed:parentid="129" ed:width="110.4" id="157" transform="matrix(1,0,0,1,632,508.6)" ed:height="23.9">
        <path fill="#fceae9" d="M0,0L110.4,0L110.4,23.9L0,23.9L0,0z"/>
        <path stroke="#696969" d="M0,23.9L110.4,23.9" fill="none" stroke-linejoin="round"/>
        <text class="st3">
            <tspan style="white-space:pre" x="1" y="15">mpu_wrappers.h</tspan>
        </text>
    </g>
    <g ed:parentid="129" ed:width="70.40000000000001" id="159" transform="matrix(1,0,0,1,632,541.2)" ed:height="23.9">
        <path fill="#fceae9" d="M0,0L70.4,0L70.4,23.9L0,23.9L0,0z"/>
        <path stroke="#696969" d="M0,23.9L70.4,23.9" fill="none" stroke-linejoin="round"/>
        <text class="st3">
            <tspan style="white-space:pre" x="1" y="15">portable.h</tspan>
        </text>
    </g>
    <g ed:parentid="129" ed:width="69.59999999999999" id="161" transform="matrix(1,0,0,1,632,573.8)" ed:height="23.9">
        <path fill="#fceae9" d="M0,0L69.6,0L69.6,23.9L0,23.9L0,0z"/>
        <path stroke="#696969" d="M0,23.9L69.6,23.9" fill="none" stroke-linejoin="round"/>
        <text class="st3">
            <tspan style="white-space:pre" x="1" y="15">projdefs.h</tspan>
        </text>
    </g>
    <g ed:parentid="129" ed:width="56" id="163" transform="matrix(1,0,0,1,632,606.4)" ed:height="23.9">
        <path fill="#fceae9" d="M0,0L56,0L56,23.9L0,23.9L0,0z"/>
        <path stroke="#696969" d="M0,23.9L56,23.9" fill="none" stroke-linejoin="round"/>
        <text class="st3">
            <tspan style="white-space:pre" x="1" y="15">queue.h</tspan>
        </text>
    </g>
    <g ed:parentid="129" ed:width="64" id="165" transform="matrix(1,0,0,1,632,639)" ed:height="23.9">
        <path fill="#fceae9" d="M0,0L64,0L64,23.9L0,23.9L0,0z"/>
        <path stroke="#696969" d="M0,23.9L64,23.9" fill="none" stroke-linejoin="round"/>
        <text class="st3">
            <tspan style="white-space:pre" x="1" y="15">semphr.h</tspan>
        </text>
    </g>
    <g ed:parentid="129" ed:width="97.59999999999999" id="167" transform="matrix(1,0,0,1,632,671.6)" ed:height="23.9">
        <path fill="#fceae9" d="M0,0L97.6,0L97.6,23.9L0,23.9L0,0z"/>
        <path stroke="#696969" d="M0,23.9L97.6,23.9" fill="none" stroke-linejoin="round"/>
        <text class="st3">
            <tspan style="white-space:pre" x="1" y="15">StackMacros.h</tspan>
        </text>
    </g>
    <g ed:parentid="129" ed:width="40.8" id="169" transform="matrix(1,0,0,1,632,704.2)" ed:height="23.9">
        <path fill="#fceae9" d="M0,0L40.8,0L40.8,23.9L0,23.9L0,0z"/>
        <path stroke="#696969" d="M0,23.9L40.8,23.9" fill="none" stroke-linejoin="round"/>
        <text class="st3">
            <tspan style="white-space:pre" x="1" y="15">task.h</tspan>
        </text>
    </g>
    <g ed:parentid="129" ed:width="56" id="171" transform="matrix(1,0,0,1,632,736.8)" ed:height="23.9">
        <path fill="#fceae9" d="M0,0L56,0L56,23.9L0,23.9L0,0z"/>
        <path stroke="#696969" d="M0,23.9L56,23.9" fill="none" stroke-linejoin="round"/>
        <text class="st3">
            <tspan style="white-space:pre" x="1" y="15">timers.h</tspan>
        </text>
    </g>
    <g ed:parentid="121" ed:width="171.2" id="173" transform="matrix(1,0,0,1,547.8,150)" ed:height="23.9">
        <path stroke="#696969" d="M0,23.9L171.2,23.9" fill="none" stroke-linejoin="round"/>
        <text class="st3">
            <tspan style="white-space:pre" x="1" y="15">CORTEX_STM32F103_Keil</tspan>
        </text>
    </g>
    <g ed:parentid="121" ed:width="216.8" id="175" transform="matrix(1,0,0,1,547.8,198.9)" ed:height="23.9">
        <path stroke="#696969" d="M0,23.9L216.8,23.9" fill="none" stroke-linejoin="round"/>
        <text class="st3">
            <tspan style="white-space:pre" x="1" y="15">CORTEX_M4F_STM32F407ZG-SK</tspan>
        </text>
    </g>
    <g ed:parentid="121" ed:width="23.2" id="177" transform="matrix(1,0,0,1,547.8,247.8)" ed:height="23.9">
        <path stroke="#696969" d="M0,23.9L23.2,23.9" fill="none" stroke-linejoin="round"/>
        <text class="st3">
            <tspan style="white-space:pre" x="1" y="15">......</tspan>
        </text>
    </g>
    <g ed:parentid="131" ed:width="28.8" id="179" transform="matrix(1,0,0,1,639.2,769.4)" ed:height="23.9">
        <path stroke="#696969" d="M0,23.9L28.8,23.9" fill="none" stroke-linejoin="round"/>
        <text class="st3">
            <tspan style="white-space:pre" x="1" y="15">Keil</tspan>
        </text>
    </g>
    <g ed:parentid="131" ed:width="40.8" id="181" transform="matrix(1,0,0,1,639.2,834.6)" ed:height="23.9">
        <path stroke="#696969" d="M0,23.9L40.8,23.9" fill="none" stroke-linejoin="round"/>
        <text class="st3">
            <tspan style="white-space:pre" x="1" y="15">RVDS</tspan>
        </text>
    </g>
    <g ed:parentid="131" ed:width="76" id="183" transform="matrix(1,0,0,1,639.2,916.1)" ed:height="23.9">
        <path stroke="#696969" d="M0,23.9L76,23.9" fill="none" stroke-linejoin="round"/>
        <text class="st3">
            <tspan style="white-space:pre" x="1" y="15">MemMang</tspan>
        </text>
    </g>
    <g ed:parentid="183" ed:width="60.8" id="185" transform="matrix(1,0,0,1,744.2,899.8)" ed:height="23.9">
        <path fill="#4dc7bc" d="M0,0L60.8,0L60.8,23.9L0,23.9L0,0z"/>
        <path stroke="#696969" d="M0,23.9L60.8,23.9" fill="none" stroke-linejoin="round"/>
        <text class="st3">
            <tspan style="white-space:pre" x="1" y="15">heap_4.c</tspan>
        </text>
    </g>
    <g ed:parentid="183" ed:width="23.2" id="187" transform="matrix(1,0,0,1,744.2,932.4)" ed:height="23.9">
        <path stroke="#696969" d="M0,23.9L23.2,23.9" fill="none" stroke-linejoin="round"/>
        <text class="st3">
            <tspan style="white-space:pre" x="1" y="15">......</tspan>
        </text>
    </g>
    <g ed:parentid="181" ed:width="80" id="189" transform="matrix(1,0,0,1,709,818.3)" ed:height="23.9">
        <path stroke="#696969" d="M0,23.9L80,23.9" fill="none" stroke-linejoin="round"/>
        <text class="st3">
            <tspan style="white-space:pre" x="1" y="15">ARM_CM4F</tspan>
        </text>
    </g>
    <g ed:parentid="181" ed:width="23.2" id="191" transform="matrix(1,0,0,1,709,867.2)" ed:height="23.9">
        <path stroke="#696969" d="M0,23.9L23.2,23.9" fill="none" stroke-linejoin="round"/>
        <text class="st3">
            <tspan style="white-space:pre" x="1" y="15">......</tspan>
        </text>
    </g>
    <g ed:parentid="189" ed:width="41.59999999999999" id="193" transform="matrix(1,0,0,1,818,802)" ed:height="23.9">
        <path fill="#4dc7bc" d="M0,0L41.6,0L41.6,23.9L0,23.9L0,0z"/>
        <path stroke="#696969" d="M0,23.9L41.6,23.9" fill="none" stroke-linejoin="round"/>
        <text class="st3">
            <tspan style="white-space:pre" x="1" y="15">port.c</tspan>
        </text>
    </g>
    <g ed:parentid="189" ed:width="83.2" id="195" transform="matrix(1,0,0,1,818,834.6)" ed:height="23.9">
        <path fill="#fceae9" d="M0,0L83.2,0L83.2,23.9L0,23.9L0,0z"/>
        <path stroke="#696969" d="M0,23.9L83.2,23.9" fill="none" stroke-linejoin="round"/>
        <text class="st3">
            <tspan style="white-space:pre" x="1" y="15">portmacro.h</tspan>
        </text>
    </g>
    <g ed:parentid="179" ed:width="212.8" id="197" transform="matrix(1,0,0,1,697,769.4)" ed:height="23.9">
        <path stroke="#696969" d="M0,23.9L212.8,23.9" fill="none" stroke-linejoin="round"/>
        <text class="st3">
            <tspan style="white-space:pre" x="1" y="15">See-also-the-RVDS-directory.txt</tspan>
        </text>
    </g>
    <g ed:parentid="175" ed:width="122.4" id="199" transform="matrix(1,0,0,1,793.6,182.6)" ed:height="23.9">
        <path fill="#fceae9" d="M0,0L122.4,0L122.4,23.9L0,23.9L0,0z"/>
        <path stroke="#696969" d="M0,23.9L122.4,23.9" fill="none" stroke-linejoin="round"/>
        <text class="st3">
            <tspan style="white-space:pre" x="1" y="15">FreeRTOSConfig.h</tspan>
        </text>
    </g>
    <g ed:parentid="175" ed:width="23.2" id="201" transform="matrix(1,0,0,1,793.6,215.2)" ed:height="23.9">
        <path stroke="#696969" d="M0,23.9L23.2,23.9" fill="none" stroke-linejoin="round"/>
        <text class="st3">
            <tspan style="white-space:pre" x="1" y="15">......</tspan>
        </text>
    </g>
    <g ed:togtopicid="101" transform="translate(270.4,695.7)">
        <use xlink:href="#minus"/>
    </g>
    <g ed:togtopicid="102" transform="translate(446.8,644.95)">
        <use xlink:href="#minus"/>
    </g>
    <g ed:togtopicid="107" transform="translate(484.4,1219.15)">
        <use xlink:href="#minus"/>
    </g>
    <g ed:togtopicid="121" transform="translate(519.8,204.85)">
        <use xlink:href="#minus"/>
    </g>
    <g ed:togtopicid="125" transform="translate(523,726.45)">
        <use xlink:href="#minus"/>
    </g>
    <g ed:togtopicid="129" transform="translate(604,530.85)">
        <use xlink:href="#minus"/>
    </g>
    <g ed:togtopicid="131" transform="translate(611.2,856.85)">
        <use xlink:href="#minus"/>
    </g>
    <g ed:togtopicid="175" transform="translate(765.6,204.85)">
        <use xlink:href="#minus"/>
    </g>
    <g ed:togtopicid="179" transform="translate(669,775.35)">
        <use xlink:href="#minus"/>
    </g>
    <g ed:togtopicid="181" transform="translate(681,840.55)">
        <use xlink:href="#minus"/>
    </g>
    <g ed:togtopicid="183" transform="translate(716.2,922.05)">
        <use xlink:href="#minus"/>
    </g>
    <g ed:togtopicid="189" transform="translate(790,824.25)">
        <use xlink:href="#minus"/>
    </g>
    <symbol id="plus">
        <path fill="url(#lg1)" d="M11,6C11,8.8,8.8,11,6,11C3.2,11,1,8.8,1,6C1,3.2,3.2,1,6,1C8.8,1,11,3.2,11,6z"/>
        <path stroke="#46a000" fill="none" d="M11,6C11,8.8,8.8,11,6,11C3.2,11,1,8.8,1,6C1,3.2,3.2,1,6,1C8.8,1,11,3.2,11,6zM3,6L9,6M6,3L6,9"/>
    </symbol>
    <symbol id="minus">
        <path fill="url(#lg1)" d="M11,6C11,8.8,8.8,11,6,11C3.2,11,1,8.8,1,6C1,3.2,3.2,1,6,1C8.8,1,11,3.2,11,6z"/>
        <path stroke="#46a000" fill="none" d="M11,6C11,8.8,8.8,11,6,11C3.2,11,1,8.8,1,6C1,3.2,3.2,1,6,1C8.8,1,11,3.2,11,6zM3,6L9,6"/>
    </symbol>
</svg>
</div>
      </div>
    </div>
    <script>eval(atob('dmFyIG11YT13aW5kb3cubmF2aWdhdG9yLnVzZXJBZ2VudDsNCnZhciB1YT0obXVhLmluZGV4T2YoJ3J2OjExJykrbXVhLmluZGV4T2YoJ01TSUUnKSk+PTA7DQpkb2N1bWVudC5nZXRFbGVtZW50QnlJZCgnc3ZnLWNvbnRhaW5lcicpLm9uY29udGV4dG1lbnUgPSBmdW5jdGlvbiAoZXZlbnQpIHsNCiAgICBldmVudC5wcmV2ZW50RGVmYXVsdCgpOw0KfQ0KZG9jdW1lbnQuZ2V0RWxlbWVudEJ5SWQoJ3N2Zy1jb250YWluZXInKS5vbm1vdXNlZG93biA9IGZ1bmN0aW9uIChldmVudCkgew0KICAgIGlmKGV2ZW50LndoaWNoID09Myl7DQogICAgICAgIHRoaXMuc3R5bGUuY3Vyc29yID0gJ3BvaW50ZXInOw0KICAgICAgICB0aGlzLm9ubW91c2Vtb3ZlID0gZnVuY3Rpb24gKGV2KSB7DQogICAgICAgICAgICB0aGlzLnNjcm9sbEJ5KC0oZXYubW92ZW1lbnRYKSwgMCk7DQogICAgICAgICAgICB3aW5kb3cuc2Nyb2xsQnkoMCwtKGV2Lm1vdmVtZW50WSkpDQogICAgICAgIH0NCiAgICAgICAgdGhpcy5vbm1vdXNldXAgPSBmdW5jdGlvbiAoKSB7DQogICAgICAgICAgICB0aGlzLnN0eWxlLmN1cnNvciA9ICBudWxsOw0KICAgICAgICAgICAgdGhpcy5vbm1vdXNldXAgPSBudWxsOw0KICAgICAgICAgICAgdGhpcy5vbm1vdXNlbW92ZSA9IG51bGw7DQogICAgICAgIH0NCiAgICB9DQp9DQpOdW1iZXIucHJvdG90eXBlLnRvc3VpdHN2Zz1mdW5jdGlvbiAoKSB7DQogICAgdmFyIG51bT10aGlzLnZhbHVlT2YoKTsNCiAgICBpZihudW0lMT09PTApew0KICAgICAgICByZXR1cm4gbnVtKzAuNQ0KICAgIH1lbHNlIHJldHVybiBudW07DQp9Ow0KTnVtYmVyLnByb3RvdHlwZS5wbHVzej1mdW5jdGlvbigpIHsNCiAgICB2YXIgbnVtPXRoaXMudmFsdWVPZigpOw0KICAgIHJldHVybiBudW08MTA/JzAnK251bTpudW07DQp9Ow0KZnVuY3Rpb24gcGFyc2VEYXRlKG51bSkgew0KICAgIHZhciBkYXRlID0gbmV3IERhdGUobnVtKTsNCiAgICB2YXIgWSA9IGRhdGUuZ2V0RnVsbFllYXIoKSArICctJzsNCiAgICB2YXIgTSA9IChkYXRlLmdldE1vbnRoKCkrMSkucGx1c3ooKSArICctJzsNCiAgICB2YXIgRCA9IGRhdGUuZ2V0RGF0ZSgpLnBsdXN6KCkgKyAnICc7DQogICAgdmFyIGggPSBkYXRlLmdldEhvdXJzKCkucGx1c3ooKSArICc6JzsNCiAgICB2YXIgbW0gPSBkYXRlLmdldE1pbnV0ZXMoKS5wbHVzeigpICsgJzonOw0KICAgIHZhciBzID0gZGF0ZS5nZXRTZWNvbmRzKCkucGx1c3ooKTsNCiAgICByZXR1cm4gWStNK0QraCttbStzOw0KfQ0KLy8tLXByZWRlZmluZWQNCi8vY29tbWVudC0tDQp2YXIgY29tbWVudHM9ZG9jdW1lbnQucXVlcnlTZWxlY3RvckFsbCgnZz5nW2VkXFw6Y29tbWVudF0nKTsNCmZ1bmN0aW9uIGdldGN3aChwb3B1cCkgew0KICAgIGRvY3VtZW50LmJvZHkuZ2V0RWxlbWVudHNCeVRhZ05hbWUoJ3N2ZycpWzBdLmFwcGVuZENoaWxkKHBvcHVwKTsNCiAgICB2YXIgdz1wb3B1cC5nZXRCb3VuZGluZ0NsaWVudFJlY3QoKS53aWR0aDsNCiAgICB2YXIgaD1wb3B1cC5nZXRCb3VuZGluZ0NsaWVudFJlY3QoKS5oZWlnaHQ7DQogICAgcmV0dXJuIFt3LGhdDQp9DQpmb3IodmFyIGk9MDtpPGNvbW1lbnRzLmxlbmd0aDtpKyspew0KICAgIHZhciBwb3B1cD1kb2N1bWVudC5jcmVhdGVFbGVtZW50TlMoJ2h0dHA6Ly93d3cudzMub3JnLzIwMDAvc3ZnJywnZycpOw0KICAgIHZhciBwb3B1cFI9IGRvY3VtZW50LmNyZWF0ZUVsZW1lbnROUygnaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmcnLCdyZWN0Jyk7DQogICAgdmFyIGhvdmVyPWRvY3VtZW50LmNyZWF0ZUVsZW1lbnROUygnaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmcnLCdyZWN0Jyk7DQogICAgdmFyIG9saW5lPWRvY3VtZW50LmNyZWF0ZUVsZW1lbnROUygnaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmcnLCdyZWN0Jyk7DQogICAgaG92ZXIuc2V0QXR0cmlidXRlKCdmaWxsJywnI2NkY2RmZicpOw0KICAgIGhvdmVyLnNldEF0dHJpYnV0ZSgneCcsJzAnKTsNCiAgICBob3Zlci5zZXRBdHRyaWJ1dGUoJ3knLCcwJyk7DQogICAgaG92ZXIuc2V0QXR0cmlidXRlKCdoZWlnaHQnLCcxNicpOw0KICAgIGhvdmVyLnNldEF0dHJpYnV0ZSgnd2lkdGgnLCcxNicpOw0KICAgIGhvdmVyLnNldEF0dHJpYnV0ZSgnZmlsbC1vcGFjaXR5JywnMC42Jyk7DQogICAgaG92ZXIuc2V0QXR0cmlidXRlKCd0cmFuc2Zvcm0nLGNvbW1lbnRzW2ldLnF1ZXJ5U2VsZWN0b3IoJ3VzZScpLmdldEF0dHJpYnV0ZSgndHJhbnNmb3JtJykpOw0KICAgIGhvdmVyLnN0eWxlLmRpc3BsYXk9J25vbmUnOw0KICAgIGNvbW1lbnRzW2ldLmFwcGVuZENoaWxkKGhvdmVyKTsNCiAgICB2YXIgYT1KU09OLnBhcnNlKGNvbW1lbnRzW2ldLmdldEF0dHJpYnV0ZSgnZWQ6Y29tbWVudCcpKTsNCiAgICB2YXIgaGVpZ2h0PTA7DQogICAgdmFyIGNhcnI9W107DQogICAgZm9yKHZhciBqPTA7ajxhLmxlbmd0aDtqKyspew0KICAgICAgICB2YXIgc3RhbXA9TnVtYmVyKGFbal0uRGF0ZSkqMTAwMDsNCiAgICAgICAgdmFyIHRpbWU9cGFyc2VEYXRlKHN0YW1wKTsNCiAgICAgICAgdmFyIG5hbWU9YVtqXS5OYW1lOw0KICAgICAgICB2YXIgbWVzc2FnZT1hW2pdLk1lc3NhZ2U7DQogICAgICAgIHZhciBtZXNzYWdlQXJyPW1lc3NhZ2Uuc3BsaXQoL1xuLyk7DQogICAgICAgIHZhciBvPWRvY3VtZW50LmNyZWF0ZUVsZW1lbnROUygnaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmcnLCdnJyk7DQogICAgICAgIHZhciBuPWRvY3VtZW50LmNyZWF0ZUVsZW1lbnROUygnaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmcnLCd0ZXh0Jyk7DQogICAgICAgIHZhciB0PWRvY3VtZW50LmNyZWF0ZUVsZW1lbnROUygnaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmcnLCd0ZXh0Jyk7DQogICAgICAgIHZhciBtPWRvY3VtZW50LmNyZWF0ZUVsZW1lbnROUygnaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmcnLCd0ZXh0Jyk7DQogICAgICAgIG4uc2V0QXR0cmlidXRlKCd4Jyw1KTsNCiAgICAgICAgbi5zZXRBdHRyaWJ1dGUoJ3knLDEyKTsNCiAgICAgICAgbi5zZXRBdHRyaWJ1dGUoJ2ZpbGwnLCcjMDA2ZWZmJyk7DQogICAgICAgIG4udGV4dENvbnRlbnQ9bmFtZSsn77yaJzsNCiAgICAgICAgbi5zZXRBdHRyaWJ1dGUoJ2ZvbnQtc2l6ZScsJzEyJyk7DQogICAgICAgIHQuc2V0QXR0cmlidXRlKCd4JywyMDApOw0KICAgICAgICB0LnNldEF0dHJpYnV0ZSgneScsMTIpOw0KICAgICAgICB0LnNldEF0dHJpYnV0ZSgnZmlsbCcsJyM5Njk2OTYnKTsNCiAgICAgICAgdC50ZXh0Q29udGVudD10aW1lOw0KICAgICAgICB0LnNldEF0dHJpYnV0ZSgnZm9udC1zaXplJywnMTAnKTsNCiAgICAgICAgbS5zZXRBdHRyaWJ1dGUoJ3RyYW5zZm9ybScsJ3RyYW5zbGF0ZSgyMCwyNyknKTsNCiAgICAgICAgbS5zZXRBdHRyaWJ1dGUoJ2ZvbnQtc2l6ZScsJzEyJyk7DQogICAgICAgIGZvcih2YXIgaz0wO2s8bWVzc2FnZUFyci5sZW5ndGg7aysrKXsNCiAgICAgICAgICAgIHZhciB0cz1kb2N1bWVudC5jcmVhdGVFbGVtZW50TlMoJ2h0dHA6Ly93d3cudzMub3JnLzIwMDAvc3ZnJywndHNwYW4nKTsNCiAgICAgICAgICAgIHRzLnNldEF0dHJpYnV0ZSgneCcsJzAnKTsNCiAgICAgICAgICAgIHRzLnNldEF0dHJpYnV0ZSgneScsayoxNik7DQogICAgICAgICAgICB0cy50ZXh0Q29udGVudD1tZXNzYWdlQXJyW2tdOw0KICAgICAgICAgICAgbS5hcHBlbmRDaGlsZCh0cyk7DQogICAgICAgIH0NCiAgICAgICAgby5zZXRBdHRyaWJ1dGUoJ3RyYW5zZm9ybScsJ3RyYW5zbGF0ZSgwLCcraGVpZ2h0KycpJyk7DQogICAgICAgIG8uYXBwZW5kQ2hpbGQobik7DQogICAgICAgIG8uYXBwZW5kQ2hpbGQodCk7DQogICAgICAgIG8uYXBwZW5kQ2hpbGQobSk7DQogICAgICAgIGNhcnIucHVzaChvKTsNCiAgICAgICAgcG9wdXAuYXBwZW5kQ2hpbGQobyk7DQogICAgICAgIGhlaWdodD0obWVzc2FnZUFyci5sZW5ndGgrMSkqMTYraGVpZ2h0Ow0KICAgIH0NCiAgICB2YXIgd2Fycj1nZXRjd2gocG9wdXApOw0KICAgIG9saW5lLnNldEF0dHJpYnV0ZSgneCcsJzAnKTsNCiAgICBvbGluZS5zZXRBdHRyaWJ1dGUoJ3knLCcwJyk7DQogICAgdmFyIG93PXdhcnJbMF0rMTAuNTsNCiAgICB2YXIgb2g9d2FyclsxXSszOw0KICAgIG9saW5lLnNldEF0dHJpYnV0ZSgnd2lkdGgnLG93KTsNCiAgICBvbGluZS5zZXRBdHRyaWJ1dGUoJ2hlaWdodCcsb2gpOw0KICAgIG9saW5lLnNldEF0dHJpYnV0ZSgnZmlsbCcsJ3doaXRlJyk7DQogICAgb2xpbmUuc2V0QXR0cmlidXRlKCdzdHJva2UnLCcjNjU2NTY1Jyk7DQogICAgcG9wdXAuYXBwZW5kQ2hpbGQob2xpbmUpOw0KICAgIHZhciBsPWNhcnIubGVuZ3RoOw0KICAgIHdoaWxlKGwtLSl7DQogICAgICAgIHBvcHVwLmFwcGVuZENoaWxkKGNhcnJbbF0pOw0KICAgIH0NCiAgICBwb3B1cC5vbm1vdXNlb3Zlcj1mdW5jdGlvbiAoKSB7DQogICAgICAgIHRoaXMuc3R5bGUuZGlzcGxheT0nYmxvY2snOw0KICAgIH07DQogICAgcG9wdXAub25tb3VzZW91dD1mdW5jdGlvbiAoKSB7DQogICAgICAgIHRoaXMuc3R5bGUuZGlzcGxheSA9ICdub25lJzsNCiAgICB9Ow0KICAgIHZhciBjcz1jb21tZW50c1tpXS5xdWVyeVNlbGVjdG9yKCd1c2UnKS5nZXRBdHRyaWJ1dGUoJ3RyYW5zZm9ybScpLm1hdGNoKC9cKChcUyp8XFMqXHNcUyopXCkvKVsxXS5zcGxpdCgvIHwsLyk7DQogICAgdmFyIHBzPWNvbW1lbnRzW2ldLnBhcmVudE5vZGUuZ2V0QXR0cmlidXRlKCd0cmFuc2Zvcm0nKTsNCiAgICBpZihwcy5zdWJzdHIoMCwyKSA9PSAndHInKXsNCiAgICAgICAgdmFyIHBwcyA9IHBzLm1hdGNoKC9cKChcUyp8XFMqXHNcUyopXCkvKVsxXS5zcGxpdCgvIHwsLyk7DQogICAgICAgIHZhciB4PXBhcnNlRmxvYXQoY3NbMF0pK3BhcnNlRmxvYXQocHBzWzBdKTsNCiAgICAgICAgdmFyIHk9cGFyc2VGbG9hdChwcHNbMV0pOw0KICAgICAgICB4PXgudG9zdWl0c3ZnKCk7DQogICAgICAgIHk9eS50b3N1aXRzdmcoKTsNCiAgICAgICAgdmFyIHRyc3RyID0gJ3RyYW5zbGF0ZSgnK3grJywnK3krJyknOw0KICAgIH0NCiAgICBlbHNlIGlmKHBzLnN1YnN0cigwLDIpID09ICdtYScpew0KICAgICAgICB2YXIgcHBzID0gcHMubWF0Y2goLyhcLT9cZCsoXC5cZCspPylbXCwgXShcLT9cZCsoXC5cZCspPylbXCwgXShcLT9cZCsoXC5cZCspPylbXCwgXShcLT9cZCsoXC5cZCspPylbXCwgXShcLT9cZCsoXC5cZCspPylbXCwgXShcLT9cZCsoXC5cZCspPylcKSQvKTsNCiAgICAgICAgdmFyIG1hQXJyID0gW3BhcnNlRmxvYXQocHBzWzFdKSxwYXJzZUZsb2F0KHBwc1szXSkscGFyc2VGbG9hdChwcHNbNV0pLHBhcnNlRmxvYXQocHBzWzddKSxwYXJzZUZsb2F0KHBwc1s5XSkscGFyc2VGbG9hdChwcHNbMTFdKV07DQogICAgICAgIGlmKG1hQXJyWzFdID09IDApew0KICAgICAgICAgICAgdmFyIHggPSBwYXJzZUZsb2F0KGNzWzBdKTsNCiAgICAgICAgICAgIHZhciB5PSAwOw0KICAgICAgICAgICAgdmFyIHgxID0geCAqIG1hQXJyWzBdICsgeSAqIG1hQXJyWzJdICsgbWFBcnJbNF07DQogICAgICAgICAgICB2YXIgeTEgPSB4ICogbWFBcnJbMV0gKyB5ICogbWFBcnJbM10gKyBtYUFycls1XTsNCiAgICAgICAgICAgIHgxPXgxLnRvc3VpdHN2ZygpOw0KICAgICAgICAgICAgeTE9eTEudG9zdWl0c3ZnKCk7DQogICAgICAgICAgICB2YXIgdHJzdHIgPSAgJ3RyYW5zbGF0ZSgnK3gxKycsJyt5MSsnKSc7DQogICAgICAgIH1lbHNlew0KICAgICAgICAgICAgdmFyIHggPSBwYXJzZUZsb2F0KGNzWzBdKSsxNjsNCiAgICAgICAgICAgIHZhciB5PSAwOw0KICAgICAgICAgICAgdmFyIHgxID0geCAqIG1hQXJyWzBdICsgeSAqIG1hQXJyWzJdICsgbWFBcnJbNF07DQogICAgICAgICAgICB2YXIgeTEgPSB4ICogbWFBcnJbMV0gKyB5ICogbWFBcnJbM10gKyBtYUFycls1XTsNCiAgICAgICAgICAgIHggPSBwYXJzZUZsb2F0KGNzWzBdKSsxNjsNCiAgICAgICAgICAgIHk9IC0xNjsNCiAgICAgICAgICAgIHZhciB4MiA9IHggKiBtYUFyclswXSArIHkgKiBtYUFyclsyXSArIG1hQXJyWzRdOw0KICAgICAgICAgICAgdmFyIHkyID0geCAqIG1hQXJyWzFdICsgeSAqIG1hQXJyWzNdICsgbWFBcnJbNV07DQogICAgICAgICAgICB2YXIgZnggPSB4MTx4Mj94MS50b3N1aXRzdmcoKTogeDIudG9zdWl0c3ZnKCk7DQogICAgICAgICAgICB2YXIgZnkgPSB5MT55Mj95MS50b3N1aXRzdmcoKTogeTIudG9zdWl0c3ZnKCk7DQogICAgICAgICAgICB2YXIgb2ZmeSA9IE1hdGguYWJzKHkxLXkyKTsNCiAgICAgICAgICAgIHZhciB0cnN0ciA9ICAndHJhbnNsYXRlKCcrZngrJywnK2Z5KycpJzsNCiAgICAgICAgICAgIHBvcHVwUi5zZXRBdHRyaWJ1dGUoJ2hlaWdodCcsb2ZmeS50b1N0cmluZygpKTsNCiAgICAgICAgICAgIHBvcHVwUi5zZXRBdHRyaWJ1dGUoJ3dpZHRoJywnMTYnKTsNCiAgICAgICAgICAgIHBvcHVwUi5zZXRBdHRyaWJ1dGUoJ3knLCgtb2ZmeSkudG9TdHJpbmcoKSk7DQogICAgICAgICAgICBwb3B1cFIuc2V0QXR0cmlidXRlKCdmaWxsJywndHJhbnNwYXJlbnQnKTsNCiAgICAgICAgICAgIHBvcHVwLmFwcGVuZENoaWxkKHBvcHVwUik7DQogICAgICAgIH0NCiAgICB9DQogICAgcG9wdXAuc2V0QXR0cmlidXRlKCd0cmFuc2Zvcm0nLHRyc3RyKTsNCiAgICBwb3B1cC5zZXRBdHRyaWJ1dGUoJ2NvbW1lbnQnLCcnKTsNCiAgICBwb3B1cC5zdHlsZS5kaXNwbGF5PSdub25lJzsNCiAgICBwb3B1cC5zZXRBdHRyaWJ1dGUoJ2VkOmNvbW1lbnRpZCcsY29tbWVudHNbaV0ucGFyZW50Tm9kZS5pZCk7DQogICAgZG9jdW1lbnQucXVlcnlTZWxlY3RvcignI3N2Zy1jb250YWluZXIgPiBzdmcnKS5hcHBlbmRDaGlsZChwb3B1cCk7DQogICAgY29tbWVudHNbaV0ub25tb3VzZW92ZXI9ZnVuY3Rpb24gKCkgew0KICAgICAgICB2YXIgY29tbWVudGlkPXRoaXMucGFyZW50Tm9kZS5pZDsNCiAgICAgICAgdGhpcy5xdWVyeVNlbGVjdG9yKCdyZWN0Jykuc3R5bGUuZGlzcGxheT0nYmxvY2snOw0KICAgICAgICBkb2N1bWVudC5xdWVyeVNlbGVjdG9yKCJnW2VkXFw6Y29tbWVudGlkPSciK2NvbW1lbnRpZCsiJ11bY29tbWVudF0iKS5zdHlsZS5kaXNwbGF5PSdibG9jayc7DQogICAgfTsNCiAgICBjb21tZW50c1tpXS5vbm1vdXNlb3V0PWZ1bmN0aW9uICgpIHsNCiAgICAgICAgdmFyIGNvbW1lbnRpZD10aGlzLnBhcmVudE5vZGUuaWQ7DQovLyAgICAgICAgd2luZG93LmdldFNlbGVjdGlvbigpLnJlbW92ZUFsbFJhbmdlcygpOw0KICAgICAgICB0aGlzLnF1ZXJ5U2VsZWN0b3IoJ3JlY3QnKS5zdHlsZS5kaXNwbGF5PSdub25lJzsNCiAgICAgICAgZG9jdW1lbnQucXVlcnlTZWxlY3RvcigiZ1tlZFxcOmNvbW1lbnRpZD0nIitjb21tZW50aWQrIiddW2NvbW1lbnRdIikuc3R5bGUuZGlzcGxheT0nbm9uZSc7DQogICAgfQ0KfQ0KLy8tLWNvbW1lbnQNCi8vbm90ZS0tDQppZighdWEpew0KICAgIHZhciBub3Rlcz1kb2N1bWVudC5xdWVyeVNlbGVjdG9yQWxsKCdnPmdbZWRcXDpub3RlXScpOw0KICAgIGZ1bmN0aW9uIGdldHdoKHMscCkgew0KICAgICAgICB2YXIgbWFpbnA9ZG9jdW1lbnQuY3JlYXRlRWxlbWVudCgnZGl2Jyk7DQogICAgICAgIG1haW5wLnN0eWxlLmNzc1RleHQ9czsNCiAgICAgICAgbWFpbnAuc3R5bGUuZGlzcGxheT0naW5saW5lLWJsb2NrJzsNCiAgICAgICAgbWFpbnAuaW5uZXJIVE1MPXA7DQogICAgICAgIGRvY3VtZW50LmJvZHkuYXBwZW5kQ2hpbGQobWFpbnApOw0KICAgICAgICB2YXIgdz1tYWlucC5jbGllbnRXaWR0aDsNCiAgICAgICAgdmFyIGg9bWFpbnAuY2xpZW50SGVpZ2h0Ow0KICAgICAgICBkb2N1bWVudC5ib2R5LnJlbW92ZUNoaWxkKG1haW5wKTsNCiAgICAgICAgcmV0dXJuIFt3LGhdDQogICAgfQ0KICAgIGZvcih2YXIgaT0wO2k8bm90ZXMubGVuZ3RoO2krKyl7DQogICAgICAgIHZhciBhPW5vdGVzW2ldLmdldEF0dHJpYnV0ZSgnZWQ6bm90ZScpOw0KCQl2YXIgbm90ZUxvY2sgPSBub3Rlc1tpXS5nZXRBdHRyaWJ1dGUoJ2VkOm5vdGVsb2NrJyk7DQogICAgICAgIGlmKG5vdGVMb2NrID09ICd0cnVlJyl7DQogICAgICAgICAgICBjb250aW51ZTsNCiAgICAgICAgfQ0KICAgICAgICB2YXIgbWFpbnA9YS5tYXRjaCgvPHAoW1xTXHNdKik8XC9wPi9nKVswXTsNCiAgICAgICAgdmFyIG1haW5zPWEubWF0Y2goL3N0eWxlPSIoLio/KSIvKVsxXTsNCiAgICAgICAgdmFyIG91dD1kb2N1bWVudC5jcmVhdGVFbGVtZW50TlMoJ2h0dHA6Ly93d3cudzMub3JnLzIwMDAvc3ZnJywnZycpOw0KICAgICAgICB2YXIgb2xpbmU9ZG9jdW1lbnQuY3JlYXRlRWxlbWVudE5TKCdodHRwOi8vd3d3LnczLm9yZy8yMDAwL3N2ZycsJ3JlY3QnKTsNCiAgICAgICAgdmFyIHBvcHVwPWRvY3VtZW50LmNyZWF0ZUVsZW1lbnROUygnaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmcnLCdmb3JlaWduT2JqZWN0Jyk7DQogICAgICAgIHZhciBwb3B1cFI9IGRvY3VtZW50LmNyZWF0ZUVsZW1lbnROUygnaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmcnLCdyZWN0Jyk7DQogICAgICAgIHZhciBob3Zlcj1kb2N1bWVudC5jcmVhdGVFbGVtZW50TlMoJ2h0dHA6Ly93d3cudzMub3JnLzIwMDAvc3ZnJywncmVjdCcpOw0KICAgICAgICBob3Zlci5zZXRBdHRyaWJ1dGUoJ2ZpbGwnLCcjY2RjZGZmJyk7DQogICAgICAgIGhvdmVyLnNldEF0dHJpYnV0ZSgneCcsJzAnKTsNCiAgICAgICAgaG92ZXIuc2V0QXR0cmlidXRlKCd5JywnMCcpOw0KICAgICAgICBob3Zlci5zZXRBdHRyaWJ1dGUoJ2hlaWdodCcsJzE2Jyk7DQogICAgICAgIGhvdmVyLnNldEF0dHJpYnV0ZSgnd2lkdGgnLCcxNicpOw0KICAgICAgICBob3Zlci5zZXRBdHRyaWJ1dGUoJ2ZpbGwtb3BhY2l0eScsJzAuNicpOw0KICAgICAgICBob3Zlci5zZXRBdHRyaWJ1dGUoJ3RyYW5zZm9ybScsbm90ZXNbaV0ucXVlcnlTZWxlY3RvcigndXNlJykuZ2V0QXR0cmlidXRlKCd0cmFuc2Zvcm0nKSk7DQogICAgICAgIGhvdmVyLnN0eWxlLmRpc3BsYXk9J25vbmUnOw0KICAgICAgICBub3Rlc1tpXS5hcHBlbmRDaGlsZChob3Zlcik7DQogICAgICAgIHBvcHVwLnN0eWxlLmNzc1RleHQ9bWFpbnM7DQogICAgICAgIHBvcHVwLmlubmVySFRNTD1tYWlucDsNCiAgICAgICAgdmFyIHdoPWdldHdoKG1haW5zLG1haW5wKTsNCiAgICAgICAgcG9wdXAuc2V0QXR0cmlidXRlKCd3aWR0aCcsd2hbMF0rMTYpOw0KICAgICAgICBwb3B1cC5zZXRBdHRyaWJ1dGUoJ2hlaWdodCcsd2hbMV0rOCk7DQogICAgICAgIHBvcHVwLnNldEF0dHJpYnV0ZSgndHJhbnNmb3JtJywndHJhbnNsYXRlKDgsNCknKTsNCiAgICAgICAgcG9wdXAuc3R5bGUudGV4dEFsaWduPSdsZWZ0JzsNCiAgICAgICAgb2xpbmUuc2V0QXR0cmlidXRlKCd4JywnMCcpOw0KICAgICAgICBvbGluZS5zZXRBdHRyaWJ1dGUoJ3knLCcwJyk7DQogICAgICAgIG9saW5lLnNldEF0dHJpYnV0ZSgnd2lkdGgnLHdoWzBdKzE2KTsNCiAgICAgICAgb2xpbmUuc2V0QXR0cmlidXRlKCdoZWlnaHQnLHdoWzFdKzgpOw0KICAgICAgICBvbGluZS5zZXRBdHRyaWJ1dGUoJ3N0cm9rZScsJyNhMjdhMDAnKTsNCiAgICAgICAgb2xpbmUuc2V0QXR0cmlidXRlKCdmaWxsJywnI2ZmZTc5ZCcpOw0KICAgICAgICBvdXQuYXBwZW5kQ2hpbGQob2xpbmUpOw0KICAgICAgICBvdXQuYXBwZW5kQ2hpbGQocG9wdXApOw0KICAgICAgICBvdXQuc2V0QXR0cmlidXRlKCdub3RlJywnJyk7DQogICAgICAgIG91dC5zdHlsZS5kaXNwbGF5PSdub25lJzsNCiAgICAgICAgb3V0LnNldEF0dHJpYnV0ZSgnZWQ6bm90ZWlkJyxub3Rlc1tpXS5wYXJlbnROb2RlLmlkKTsNCiAgICAgICAgb3V0Lm9ubW91c2VvdmVyPWZ1bmN0aW9uICgpIHsNCiAgICAgICAgICAgIHRoaXMuc3R5bGUuZGlzcGxheT0nYmxvY2snOw0KICAgICAgICB9Ow0KICAgICAgICBvdXQub25tb3VzZW91dD1mdW5jdGlvbiAoKSB7DQovLyAgICAgICAgd2luZG93LmdldFNlbGVjdGlvbiA/IHdpbmRvdy5nZXRTZWxlY3Rpb24oKS5yZW1vdmVSYW5nZSh3aW5kb3cuZ2V0U2VsZWN0aW9uKCkucmUpOmRvY3VtZW50LnNlbGVjdGlvbi5lbXB0eSgpOw0KDQogICAgICAgICAgICB0aGlzLnN0eWxlLmRpc3BsYXk9J25vbmUnOw0KICAgICAgICB9Ow0KICAgICAgICB2YXIgY3M9bm90ZXNbaV0ucXVlcnlTZWxlY3RvcigndXNlJykuZ2V0QXR0cmlidXRlKCd0cmFuc2Zvcm0nKS5tYXRjaCgvXCgoXFMqfFxTKlxzXFMqKVwpLylbMV0uc3BsaXQoLyB8LC8pOw0KICAgICAgICB2YXIgcHM9bm90ZXNbaV0ucGFyZW50Tm9kZS5nZXRBdHRyaWJ1dGUoJ3RyYW5zZm9ybScpOw0KICAgICAgICBpZihwcy5zdWJzdHIoMCwyKSA9PSAndHInKXsNCiAgICAgICAgICAgIHZhciBwcHMgPSBwcy5tYXRjaCgvXCgoXFMqfFxTKlxzXFMqKVwpLylbMV0uc3BsaXQoLyB8LC8pOw0KICAgICAgICAgICAgdmFyIHg9cGFyc2VGbG9hdChjc1swXSkrcGFyc2VGbG9hdChwcHNbMF0pOw0KICAgICAgICAgICAgdmFyIHk9cGFyc2VGbG9hdChwcHNbMV0pOw0KICAgICAgICAgICAgeD14LnRvc3VpdHN2ZygpOw0KICAgICAgICAgICAgeT15LnRvc3VpdHN2ZygpOw0KICAgICAgICAgICAgdmFyIHRyc3RyID0gJ3RyYW5zbGF0ZSgnK3grJywnK3krJyknOw0KICAgICAgICB9ZWxzZSBpZihwcy5zdWJzdHIoMCwyKSA9PSAnbWEnKXsNCiAgICAgICAgICAgIHZhciBwcHMgPSBwcy5tYXRjaCgvKFwtP1xkKyhcLlxkKyk/KVtcLCBdKFwtP1xkKyhcLlxkKyk/KVtcLCBdKFwtP1xkKyhcLlxkKyk/KVtcLCBdKFwtP1xkKyhcLlxkKyk/KVtcLCBdKFwtP1xkKyhcLlxkKyk/KVtcLCBdKFwtP1xkKyhcLlxkKyk/KVwpJC8pOw0KICAgICAgICAgICAgdmFyIG1hQXJyID0gW3BhcnNlRmxvYXQocHBzWzFdKSxwYXJzZUZsb2F0KHBwc1szXSkscGFyc2VGbG9hdChwcHNbNV0pLHBhcnNlRmxvYXQocHBzWzddKSxwYXJzZUZsb2F0KHBwc1s5XSkscGFyc2VGbG9hdChwcHNbMTFdKV07DQogICAgICAgICAgICBpZihtYUFyclsxXSA9PSAwKXsNCiAgICAgICAgICAgICAgICB2YXIgeCA9IHBhcnNlRmxvYXQoY3NbMF0pOw0KICAgICAgICAgICAgICAgIHZhciB5PSAwOw0KICAgICAgICAgICAgICAgIHZhciB4MSA9IHggKiBtYUFyclswXSArIHkgKiBtYUFyclsyXSArIG1hQXJyWzRdOw0KICAgICAgICAgICAgICAgIHZhciB5MSA9IHggKiBtYUFyclsxXSArIHkgKiBtYUFyclszXSArIG1hQXJyWzVdOw0KICAgICAgICAgICAgICAgIHgxPXgxLnRvc3VpdHN2ZygpOw0KICAgICAgICAgICAgICAgIHkxPXkxLnRvc3VpdHN2ZygpOw0KICAgICAgICAgICAgICAgIHZhciB0cnN0ciA9ICAndHJhbnNsYXRlKCcreDErJywnK3kxKycpJzsNCiAgICAgICAgICAgIH1lbHNlew0KICAgICAgICAgICAgICAgIHZhciB4ID0gcGFyc2VGbG9hdChjc1swXSkrMTY7DQogICAgICAgICAgICAgICAgdmFyIHk9IDA7DQogICAgICAgICAgICAgICAgdmFyIHgxID0geCAqIG1hQXJyWzBdICsgeSAqIG1hQXJyWzJdICsgbWFBcnJbNF07DQogICAgICAgICAgICAgICAgdmFyIHkxID0geCAqIG1hQXJyWzFdICsgeSAqIG1hQXJyWzNdICsgbWFBcnJbNV07DQogICAgICAgICAgICAgICAgeCA9IHBhcnNlRmxvYXQoY3NbMF0pKzE2Ow0KICAgICAgICAgICAgICAgIHk9IC0xNjsNCiAgICAgICAgICAgICAgICB2YXIgeDIgPSB4ICogbWFBcnJbMF0gKyB5ICogbWFBcnJbMl0gKyBtYUFycls0XTsNCiAgICAgICAgICAgICAgICB2YXIgeTIgPSB4ICogbWFBcnJbMV0gKyB5ICogbWFBcnJbM10gKyBtYUFycls1XTsNCiAgICAgICAgICAgICAgICB2YXIgZnggPSB4MTx4Mj94MS50b3N1aXRzdmcoKTogeDIudG9zdWl0c3ZnKCk7DQogICAgICAgICAgICAgICAgdmFyIGZ5ID0geTE+eTI/eTEudG9zdWl0c3ZnKCk6IHkyLnRvc3VpdHN2ZygpOw0KICAgICAgICAgICAgICAgIHZhciB0cnN0ciA9ICAndHJhbnNsYXRlKCcrZngrJywnK2Z5KycpJzsNCiAgICAgICAgICAgICAgICBwb3B1cFIuc2V0QXR0cmlidXRlKCdoZWlnaHQnLG9mZnkudG9TdHJpbmcoKSk7DQogICAgICAgICAgICAgICAgcG9wdXBSLnNldEF0dHJpYnV0ZSgnd2lkdGgnLCcxNicpOw0KICAgICAgICAgICAgICAgIHBvcHVwUi5zZXRBdHRyaWJ1dGUoJ3knLCgtb2ZmeSkudG9TdHJpbmcoKSk7DQogICAgICAgICAgICAgICAgcG9wdXBSLnNldEF0dHJpYnV0ZSgnZmlsbCcsJ3RyYW5zcGFyZW50Jyk7DQogICAgICAgICAgICAgICAgcG9wdXAuYXBwZW5kQ2hpbGQocG9wdXBSKTsNCiAgICAgICAgICAgIH0NCiAgICAgICAgfQ0KICAgICAgICBvdXQuc2V0QXR0cmlidXRlKCd0cmFuc2Zvcm0nLHRyc3RyKTsNCiAgICAgICAgZG9jdW1lbnQucXVlcnlTZWxlY3RvcignI3N2Zy1jb250YWluZXIgPiBzdmcnKS5hcHBlbmRDaGlsZChvdXQpOw0KICAgICAgICBub3Rlc1tpXS5vbm1vdXNlb3Zlcj1mdW5jdGlvbiAoKSB7DQogICAgICAgICAgICB2YXIgbm90ZWlkPXRoaXMucGFyZW50Tm9kZS5pZDsNCiAgICAgICAgICAgIHRoaXMucXVlcnlTZWxlY3RvcigncmVjdCcpLnN0eWxlLmRpc3BsYXk9J2Jsb2NrJzsNCiAgICAgICAgICAgIGRvY3VtZW50LnF1ZXJ5U2VsZWN0b3IoImdbZWRcXDpub3RlaWQ9JyIrbm90ZWlkKyInXVtub3RlXSIpLnN0eWxlLmRpc3BsYXk9J2Jsb2NrJzsNCiAgICAgICAgfTsNCiAgICAgICAgbm90ZXNbaV0ub25tb3VzZW91dD1mdW5jdGlvbiAoKSB7DQogICAgICAgICAgICB2YXIgbm90ZWlkPXRoaXMucGFyZW50Tm9kZS5pZDsNCi8vICAgICAgICB3aW5kb3cuZ2V0U2VsZWN0aW9uKCkucmVtb3ZlQWxsUmFuZ2VzKCk7DQogICAgICAgICAgICB0aGlzLnF1ZXJ5U2VsZWN0b3IoJ3JlY3QnKS5zdHlsZS5kaXNwbGF5PSdub25lJzsNCiAgICAgICAgICAgIGRvY3VtZW50LnF1ZXJ5U2VsZWN0b3IoImdbZWRcXDpub3RlaWQ9JyIrbm90ZWlkKyInXVtub3RlXSIpLnN0eWxlLmRpc3BsYXk9J25vbmUnOw0KICAgICAgICB9DQogICAgfQ0KfWVsc2V7DQogICAgY29uc29sZS5sb2coJ+aKseatie+8jElF5rWP6KeI5Zmo5LiN5pSv5oyBbm90Zeino+aekO+8jOivt+S9v+eUqOWFtuS7luWGheaguOa1j+iniOWZqOOAguiwouiwou+8gScpDQp9DQovLy0tbm90ZQ0KLy9oeXBlcmxpbmstLQ0KdmFyIGxpbmtzPWRvY3VtZW50LnF1ZXJ5U2VsZWN0b3JBbGwoJ2c+Z1tlZFxcOmh5cGVybGlua10nKTsNCmZ1bmN0aW9uIGdldG1heGxlbihhcnIsYnJyKSB7DQogICAgdmFyIGw9MDsNCiAgICB2YXIgbGw9MDsNCiAgICBmb3IodmFyIGo9MDtqPGFyci5sZW5ndGg7aisrKXsNCiAgICAgICAgdmFyIGU9ZG9jdW1lbnQuY3JlYXRlRWxlbWVudE5TKCdodHRwOi8vd3d3LnczLm9yZy8yMDAwL3N2ZycsJ3RleHQnKTsNCiAgICAgICAgaWYoIWlzTmFOKGxpbmthcnJbal0pKXsNCiAgICAgICAgICAgIGUudGV4dENvbnRlbnQ9J1BhZ2UtJythcnJbal07DQogICAgICAgIH1lbHNlew0KICAgICAgICAgICAgZS50ZXh0Q29udGVudD1hcnJbal07DQogICAgICAgIH0NCiAgICAgICAgZS5zdHlsZS5mb250U2l6ZT0nMTJweCc7DQogICAgICAgIGRvY3VtZW50LmJvZHkuZ2V0RWxlbWVudHNCeVRhZ05hbWUoJ3N2ZycpWzBdLmFwcGVuZENoaWxkKGUpOw0KICAgICAgICB2YXIgZXc9ZS5nZXRCQm94KCkud2lkdGg7DQogICAgICAgIGRvY3VtZW50LmJvZHkuZ2V0RWxlbWVudHNCeVRhZ05hbWUoJ3N2ZycpWzBdLnJlbW92ZUNoaWxkKGUpOw0KICAgICAgICB2YXIgaD1kb2N1bWVudC5jcmVhdGVFbGVtZW50TlMoJ2h0dHA6Ly93d3cudzMub3JnLzIwMDAvc3ZnJywndGV4dCcpOw0KICAgICAgICBoLnRleHRDb250ZW50PWJycltqXTsNCiAgICAgICAgaC5zdHlsZS5mb250U2l6ZT0nMTJweCc7DQogICAgICAgIGguc3R5bGUuZm9udFdlaWdodD0nYm9sZCc7DQogICAgICAgIGRvY3VtZW50LmJvZHkuZ2V0RWxlbWVudHNCeVRhZ05hbWUoJ3N2ZycpWzBdLmFwcGVuZENoaWxkKGgpOw0KICAgICAgICB2YXIgaHc9aC5nZXRCQm94KCkud2lkdGg7DQogICAgICAgIGRvY3VtZW50LmJvZHkuZ2V0RWxlbWVudHNCeVRhZ05hbWUoJ3N2ZycpWzBdLnJlbW92ZUNoaWxkKGgpOw0KICAgICAgICBsPWV3Pmh3P2V3Omh3Ow0KICAgICAgICBsbD1sPmxsP2w6bGw7DQogICAgfQ0KICAgIHJldHVybiBsbDsNCn0NCmZvcih2YXIgaT0wO2k8bGlua3MubGVuZ3RoO2krKyl7DQogICAgdmFyIHBvcHVwPWRvY3VtZW50LmNyZWF0ZUVsZW1lbnROUygnaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmcnLCdnJyk7DQogICAgdmFyIHBvcHVwUj0gZG9jdW1lbnQuY3JlYXRlRWxlbWVudE5TKCdodHRwOi8vd3d3LnczLm9yZy8yMDAwL3N2ZycsJ3JlY3QnKTsNCiAgICB2YXIgaG92ZXI9ZG9jdW1lbnQuY3JlYXRlRWxlbWVudE5TKCdodHRwOi8vd3d3LnczLm9yZy8yMDAwL3N2ZycsJ3JlY3QnKTsNCiAgICB2YXIgZGVzY2Fycj1bXTsNCiAgICB2YXIgbGlua2Fycj1bXTsNCiAgICBob3Zlci5zZXRBdHRyaWJ1dGUoJ2ZpbGwnLCcjY2RjZGZmJyk7DQogICAgaG92ZXIuc2V0QXR0cmlidXRlKCd4JywnMCcpOw0KICAgIGhvdmVyLnNldEF0dHJpYnV0ZSgneScsJzAnKTsNCiAgICBob3Zlci5zZXRBdHRyaWJ1dGUoJ2hlaWdodCcsJzE2Jyk7DQogICAgaG92ZXIuc2V0QXR0cmlidXRlKCd3aWR0aCcsJzE2Jyk7DQogICAgaG92ZXIuc2V0QXR0cmlidXRlKCdmaWxsLW9wYWNpdHknLCcwLjYnKTsNCiAgICBob3Zlci5zZXRBdHRyaWJ1dGUoJ3RyYW5zZm9ybScsbGlua3NbaV0ucXVlcnlTZWxlY3RvcigndXNlJykuZ2V0QXR0cmlidXRlKCd0cmFuc2Zvcm0nKSk7DQogICAgaG92ZXIuc3R5bGUuZGlzcGxheT0nbm9uZSc7DQogICAgbGlua3NbaV0uYXBwZW5kQ2hpbGQoaG92ZXIpOw0KICAgIC8vIGNvbnNvbGUubG9nKGxpbmtzW2ldLmdldEF0dHJpYnV0ZSgnZWQ6aHlwZXJsaW5rJykpOw0KICAgIHZhciBhPUpTT04ucGFyc2UobGlua3NbaV0uZ2V0QXR0cmlidXRlKCdlZDpoeXBlcmxpbmsnKSk7DQogICAgdmFyIGNzPWxpbmtzW2ldLnF1ZXJ5U2VsZWN0b3IoJ3VzZScpLmdldEF0dHJpYnV0ZSgndHJhbnNmb3JtJykubWF0Y2goL1woKFxTKnxcUypcc1xTKilcKS8pWzFdLnNwbGl0KC8gfCwvKTsNCiAgICB2YXIgcHM9bGlua3NbaV0ucGFyZW50Tm9kZS5nZXRBdHRyaWJ1dGUoJ3RyYW5zZm9ybScpOw0KICAgIGlmKHBzLnN1YnN0cigwLDIpID09ICd0cicpew0KICAgICAgICB2YXIgcHBzID0gcHMubWF0Y2goL1woKFxTKnxcUypcc1xTKilcKS8pWzFdLnNwbGl0KC8gfCwvKTsNCiAgICAgICAgdmFyIHg9cGFyc2VGbG9hdChjc1swXSkrcGFyc2VGbG9hdChwcHNbMF0pOw0KICAgICAgICB2YXIgeT1wYXJzZUZsb2F0KHBwc1sxXSk7DQogICAgICAgIHg9eC50b3N1aXRzdmcoKTsNCiAgICAgICAgeT15LnRvc3VpdHN2ZygpOw0KICAgICAgICB2YXIgdHJzdHIgPSAndHJhbnNsYXRlKCcreCsnLCcreSsnKSc7DQogICAgfWVsc2UgaWYocHMuc3Vic3RyKDAsMikgPT0gJ21hJyl7DQogICAgICAgIHZhciBwcHMgPSBwcy5tYXRjaCgvKFwtP1xkKyhcLlxkKyk/KVtcLCBdKFwtP1xkKyhcLlxkKyk/KVtcLCBdKFwtP1xkKyhcLlxkKyk/KVtcLCBdKFwtP1xkKyhcLlxkKyk/KVtcLCBdKFwtP1xkKyhcLlxkKyk/KVtcLCBdKFwtP1xkKyhcLlxkKyk/KVwpJC8pOw0KICAgICAgICB2YXIgbWFBcnIgPSBbcGFyc2VGbG9hdChwcHNbMV0pLHBhcnNlRmxvYXQocHBzWzNdKSxwYXJzZUZsb2F0KHBwc1s1XSkscGFyc2VGbG9hdChwcHNbN10pLHBhcnNlRmxvYXQocHBzWzldKSxwYXJzZUZsb2F0KHBwc1sxMV0pXTsNCiAgICAgICAgaWYobWFBcnJbMV0gPT0gMCl7DQogICAgICAgICAgICB2YXIgeCA9IHBhcnNlRmxvYXQoY3NbMF0pOw0KICAgICAgICAgICAgdmFyIHk9IDA7DQogICAgICAgICAgICB2YXIgeDEgPSB4ICogbWFBcnJbMF0gKyB5ICogbWFBcnJbMl0gKyBtYUFycls0XTsNCiAgICAgICAgICAgIHZhciB5MSA9IHggKiBtYUFyclsxXSArIHkgKiBtYUFyclszXSArIG1hQXJyWzVdOw0KICAgICAgICAgICAgeDE9eDEudG9zdWl0c3ZnKCk7DQogICAgICAgICAgICB5MT15MS50b3N1aXRzdmcoKTsNCiAgICAgICAgICAgIHZhciB0cnN0ciA9ICAndHJhbnNsYXRlKCcreDErJywnK3kxKycpJzsNCiAgICAgICAgfWVsc2V7DQogICAgICAgICAgICB2YXIgeCA9IHBhcnNlRmxvYXQoY3NbMF0pKzE2Ow0KICAgICAgICAgICAgdmFyIHk9IDA7DQogICAgICAgICAgICB2YXIgeDEgPSB4ICogbWFBcnJbMF0gKyB5ICogbWFBcnJbMl0gKyBtYUFycls0XTsNCiAgICAgICAgICAgIHZhciB5MSA9IHggKiBtYUFyclsxXSArIHkgKiBtYUFyclszXSArIG1hQXJyWzVdOw0KICAgICAgICAgICAgeCA9IHBhcnNlRmxvYXQoY3NbMF0pKzE2Ow0KICAgICAgICAgICAgeT0gLTE2Ow0KICAgICAgICAgICAgdmFyIHgyID0geCAqIG1hQXJyWzBdICsgeSAqIG1hQXJyWzJdICsgbWFBcnJbNF07DQogICAgICAgICAgICB2YXIgeTIgPSB4ICogbWFBcnJbMV0gKyB5ICogbWFBcnJbM10gKyBtYUFycls1XTsNCiAgICAgICAgICAgIHZhciBmeCA9IHgxPHgyP3gxLnRvc3VpdHN2ZygpOiB4Mi50b3N1aXRzdmcoKTsNCiAgICAgICAgICAgIHZhciBmeSA9IHkxPnkyP3kxLnRvc3VpdHN2ZygpOiB5Mi50b3N1aXRzdmcoKTsNCiAgICAgICAgICAgIHZhciB0cnN0ciA9ICAndHJhbnNsYXRlKCcrZngrJywnK2Z5KycpJzsNCiAgICAgICAgICAgIHBvcHVwUi5zZXRBdHRyaWJ1dGUoJ2hlaWdodCcsb2ZmeS50b1N0cmluZygpKTsNCiAgICAgICAgICAgIHBvcHVwUi5zZXRBdHRyaWJ1dGUoJ3dpZHRoJywnMTYnKTsNCiAgICAgICAgICAgIHBvcHVwUi5zZXRBdHRyaWJ1dGUoJ3knLCgtb2ZmeSkudG9TdHJpbmcoKSk7DQogICAgICAgICAgICBwb3B1cFIuc2V0QXR0cmlidXRlKCdmaWxsJywndHJhbnNwYXJlbnQnKTsNCiAgICAgICAgICAgIHBvcHVwLmFwcGVuZENoaWxkKHBvcHVwUik7DQogICAgICAgIH0NCiAgICB9DQogICAgdmFyIGFsPWEubGVuZ3RoOw0KICAgIGZvcih2YXIgaj0wO2o8YWw7aisrKXsNCiAgICAgICAgbGlua2Fyci5wdXNoKGFbal0ubGluayk7DQogICAgICAgIGRlc2NhcnIucHVzaChhW2pdLmRlc2MpOw0KICAgIH0NCiAgICBwb3B1cC5zZXRBdHRyaWJ1dGUoJ3RyYW5zZm9ybScsdHJzdHIpOw0KICAgIHZhciBtYXg9Z2V0bWF4bGVuKGxpbmthcnIsZGVzY2Fycik7DQogICAgZm9yKHZhciBrPTA7azxhbDtrKyspew0KICAgICAgICB2YXIgYz1kb2N1bWVudC5jcmVhdGVFbGVtZW50TlMoJ2h0dHA6Ly93d3cudzMub3JnLzIwMDAvc3ZnJywnYScpOw0KICAgICAgICB2YXIgZD1kb2N1bWVudC5jcmVhdGVFbGVtZW50TlMoJ2h0dHA6Ly93d3cudzMub3JnLzIwMDAvc3ZnJywncmVjdCcpOw0KICAgICAgICB2YXIgZT1kb2N1bWVudC5jcmVhdGVFbGVtZW50TlMoJ2h0dHA6Ly93d3cudzMub3JnLzIwMDAvc3ZnJywndGV4dCcpOw0KICAgICAgICB2YXIgZj1kb2N1bWVudC5jcmVhdGVFbGVtZW50TlMoJ2h0dHA6Ly93d3cudzMub3JnLzIwMDAvc3ZnJywndGV4dCcpOw0KICAgICAgICBpZihpc05hTihsaW5rYXJyW2tdKSl7DQogICAgICAgICAgICBjLnNldEF0dHJpYnV0ZSgnaHJlZicsbGlua2FycltrXSk7DQogICAgICAgICAgICBjLnNldEF0dHJpYnV0ZSgndGFyZ2V0JywnX2JsYW5rJyk7DQogICAgICAgICAgICBlLnRleHRDb250ZW50PWxpbmthcnJba107DQogICAgICAgIH1lbHNlew0KICAgICAgICAgICAgZS50ZXh0Q29udGVudD0nUGFnZS0nK2xpbmthcnJba107DQogICAgICAgICAgICBjLnNldEF0dHJpYnV0ZSgnaHJlZicsJyMnK2xpbmthcnJba10pOw0KICAgICAgICB9DQogICAgICAgIGQuc2V0QXR0cmlidXRlKCd3aWR0aCcsbWF4KzEwKTsNCiAgICAgICAgZC5zZXRBdHRyaWJ1dGUoJ2hlaWdodCcsJzMzJyk7DQogICAgICAgIGQuc2V0QXR0cmlidXRlKCdzdHJva2UnLCcjOTk5OTk5Jyk7DQogICAgICAgIGQuc2V0QXR0cmlidXRlKCdmaWxsJywnd2hpdGUnKTsNCiAgICAgICAgZC5zZXRBdHRyaWJ1dGUoJ3knLDMzKmspOw0KICAgICAgICBmLnRleHRDb250ZW50PWRlc2NhcnJba107DQogICAgICAgIGYuc3R5bGUuZm9udFNpemU9JzEycHgnOw0KICAgICAgICBmLnN0eWxlLmZvbnRXZWlnaHQ9J2JvbGQnOw0KICAgICAgICBmLnNldEF0dHJpYnV0ZSgneCcsNSk7DQogICAgICAgIGYuc2V0QXR0cmlidXRlKCd5JywzMyprKzEyKTsNCiAgICAgICAgZS5zdHlsZS5mb250U2l6ZT0nMTJweCc7DQogICAgICAgIGUuc2V0QXR0cmlidXRlKCd5JywzMyprKzI4KTsNCiAgICAgICAgZS5zZXRBdHRyaWJ1dGUoJ3gnLDUpOw0KICAgICAgICBjLmFwcGVuZENoaWxkKGQpOw0KICAgICAgICBjLmFwcGVuZENoaWxkKGYpOw0KICAgICAgICBjLmFwcGVuZENoaWxkKGUpOw0KICAgICAgICBjLm9ubW91c2VvdmVyPWZ1bmN0aW9uICgpIHsNCiAgICAgICAgICAgIHRoaXMucXVlcnlTZWxlY3RvcigncmVjdCcpLnN0eWxlLmZpbGw9JyNlMWUxZmYnDQogICAgICAgIH07DQogICAgICAgIGMub25tb3VzZW91dD1mdW5jdGlvbiAoKSB7DQogICAgICAgICAgICB0aGlzLnF1ZXJ5U2VsZWN0b3IoJ3JlY3QnKS5zdHlsZS5maWxsPSd3aGl0ZScNCiAgICAgICAgfTsNCiAgICAgICAgcG9wdXAuYXBwZW5kQ2hpbGQoYyk7DQogICAgfQ0KICAgIHBvcHVwLnN0eWxlLmRpc3BsYXk9J25vbmUnOw0KICAgIHBvcHVwLnNldEF0dHJpYnV0ZSgnaHlwZXJsaW5rJywnJyk7DQogICAgcG9wdXAuc2V0QXR0cmlidXRlKCdlZDpsaW5raWQnLGxpbmtzW2ldLnBhcmVudE5vZGUuaWQpOw0KICAgIHBvcHVwLm9ubW91c2VvdmVyPWZ1bmN0aW9uICgpIHsNCiAgICAgICAgdGhpcy5zdHlsZS5kaXNwbGF5PSdibG9jayc7DQogICAgfTsNCiAgICBwb3B1cC5vbmNsaWNrPWZ1bmN0aW9uICgpIHsNCiAgICAgICAgdGhpcy5zdHlsZS5kaXNwbGF5PSdub25lJzsNCiAgICB9Ow0KICAgIHBvcHVwLm9ubW91c2VvdXQ9ZnVuY3Rpb24gKCkgew0KICAgICAgICB0aGlzLnN0eWxlLmRpc3BsYXk9J25vbmUnOw0KICAgIH07DQogICAgZG9jdW1lbnQucXVlcnlTZWxlY3RvcignI3N2Zy1jb250YWluZXIgPiBzdmcnKS5hcHBlbmRDaGlsZChwb3B1cCk7DQogICAgbGlua3NbaV0ub25tb3VzZW92ZXI9ZnVuY3Rpb24gKCkgew0KICAgICAgICB2YXIgbGlua2lkPXRoaXMucGFyZW50Tm9kZS5pZDsNCiAgICAgICAgdGhpcy5xdWVyeVNlbGVjdG9yKCdyZWN0Jykuc3R5bGUuZGlzcGxheT0nYmxvY2snOw0KICAgICAgICBkb2N1bWVudC5xdWVyeVNlbGVjdG9yKCJnW2VkXFw6bGlua2lkPSciK2xpbmtpZCsiJ11baHlwZXJsaW5rXSIpLnN0eWxlLmRpc3BsYXk9J2Jsb2NrJzsNCiAgICB9DQogICAgbGlua3NbaV0ub25tb3VzZW91dD1mdW5jdGlvbiAoKSB7DQogICAgICAgIHZhciBsaW5raWQ9dGhpcy5wYXJlbnROb2RlLmlkOw0KICAgICAgICB0aGlzLnF1ZXJ5U2VsZWN0b3IoJ3JlY3QnKS5zdHlsZS5kaXNwbGF5PSdub25lJzsNCiAgICAgICAgZG9jdW1lbnQucXVlcnlTZWxlY3RvcigiZ1tlZFxcOmxpbmtpZD0nIitsaW5raWQrIiddW2h5cGVybGlua10iKS5zdHlsZS5kaXNwbGF5PSdub25lJzsNCiAgICB9DQp9DQovLy0taHlwZXJsaW5rDQovL2luaXRpYWxpemUtLQ0KdmFyIHNoYXBlPWRvY3VtZW50LnF1ZXJ5U2VsZWN0b3JBbGwoJ2dbZWRcXDp0b2d0b3BpY2lkXScpOw0KdmFyIG1JZD1kb2N1bWVudC5xdWVyeVNlbGVjdG9yQWxsKCdnW2VkXFw6dG9waWN0eXBlXScpOw0KdmFyIGRhdGFUcmVlPXt9Ow0KdmFyIGV4dHJhUmVsYT17fTsNCnZhciBjaGVja0lEPScnOw0KZm9yKHZhciBpPTA7aTxtSWQubGVuZ3RoO2krKyl7DQogICAgdmFyIHR5cGU9bUlkW2ldLmdldEF0dHJpYnV0ZSgnZWQ6dG9waWN0eXBlJyk7DQogICAgdmFyIHNpZD1tSWRbaV0uaWQ7DQogICAgaWYodHlwZSE9PSdjYWxsb3V0Jyl7DQogICAgICAgIGluaXQoc2lkLGRhdGFUcmVlKQ0KICAgIH0NCn0NCmZ1bmN0aW9uIGluaXQoaWQsIG9iaikgew0KICAgIHZhciBjaGlsZHMgPSBkb2N1bWVudC5xdWVyeVNlbGVjdG9yQWxsKCJnW2VkXFw6cGFyZW50aWQ9JyIgKyBpZCArICInXTpub3QoW2VkXFw6dG9waWN0eXBlXSkiKTsNCiAgICB2YXIgY2FsbHMgPSBkb2N1bWVudC5xdWVyeVNlbGVjdG9yQWxsKCJnW2VkXFw6cGFyZW50aWQ9JyIgKyBpZCArICInXVtlZFxcOnRvcGljdHlwZV0iKTsNCiAgICB2YXIgc3VtbWFyeSA9IGRvY3VtZW50LnF1ZXJ5U2VsZWN0b3JBbGwoInBhdGhbZWRcXDpwYXJlbnRpZCo9JyIgKyBpZCArICInXVtlZFxcOnR5cGU9J3N1bW1hcnknXSIpOw0KICAgIHZhciBib3VuZGFyeT0gZG9jdW1lbnQucXVlcnlTZWxlY3RvckFsbCgicGF0aFtlZFxcOnBhcmVudGlkKj0nIiArIGlkICsgIiddW2VkXFw6dHlwZT0nYm91bmRhcnknXSIpOw0KICAgIHZhciByZWxhZnJvbT1kb2N1bWVudC5xdWVyeVNlbGVjdG9yQWxsKCJnW2VkXFw6ZnJvbWlkKj0nIiArIGlkICsgIiddW2VkXFw6dHlwZT0ncmVsYXRpb24nXSIpOw0KICAgIHZhciByZWxhdG89ZG9jdW1lbnQucXVlcnlTZWxlY3RvckFsbCgiZ1tlZFxcOnRvaWQqPSciICsgaWQgKyAiJ11bZWRcXDp0eXBlPSdyZWxhdGlvbiddIik7DQogICAgb2JqWyJtIiArIGlkXSA9IHt9Ow0KICAgIHZhciB0eXBlID0gZG9jdW1lbnQuZ2V0RWxlbWVudEJ5SWQoaWQpLmdldEF0dHJpYnV0ZSgnZWQ6dG9waWN0eXBlJyk7DQogICAgdmFyIGl3PWRvY3VtZW50LmdldEVsZW1lbnRCeUlkKGlkKS5nZXRBdHRyaWJ1dGUoJ2VkOndpZHRoJyk7DQogICAgdmFyIGloPWRvY3VtZW50LmdldEVsZW1lbnRCeUlkKGlkKS5nZXRBdHRyaWJ1dGUoJ2VkOmhlaWdodCcpOw0KICAgIGlmICh0eXBlKSB7DQogICAgICAgIG9ialsibSIgKyBpZF0udHlwZSA9IHR5cGU7DQogICAgfQ0KICAgIGlmKGl3JiZpaCl7DQogICAgICAgIG9ialsibSIgKyBpZF0ud2lkdGggPWl3Ow0KICAgICAgICBvYmpbIm0iICsgaWRdLmhlaWdodCA9aWg7DQogICAgfQ0KICAgIGlmIChyZWxhZnJvbS5sZW5ndGggIT09IDApIHsNCiAgICAgICAgb2JqWyJtIiArIGlkXS5yZWxhZnJvbSA9IHt9Ow0KICAgICAgICBmb3IgKHZhciBpID0gMDsgaSA8IHJlbGFmcm9tLmxlbmd0aDsgaSsrKSB7DQogICAgICAgICAgICB2YXIgaW5kZXhpZCA9IHJlbGFmcm9tW2ldLmlkOw0KICAgICAgICAgICAgdmFyIHRvaWQgPSBkb2N1bWVudC5nZXRFbGVtZW50QnlJZChpbmRleGlkKS5nZXRBdHRyaWJ1dGUoJ2VkOnRvaWQnKTsNCiAgICAgICAgICAgIGlmIChleHRyYVJlbGFbaW5kZXhpZF0gPT09IHVuZGVmaW5lZCkgew0KICAgICAgICAgICAgICAgIGV4dHJhUmVsYVtpbmRleGlkXSA9IHsNCiAgICAgICAgICAgICAgICAgICAgaWQ6IGluZGV4aWQsDQogICAgICAgICAgICAgICAgICAgIGZyb21pZDogaWQsDQogICAgICAgICAgICAgICAgICAgIHRvaWQ6IHRvaWQsDQogICAgICAgICAgICAgICAgICAgIGlzQzogZmFsc2UNCiAgICAgICAgICAgICAgICB9Ow0KICAgICAgICAgICAgfQ0KICAgICAgICAgICAgb2JqWyJtIiArIGlkXS5yZWxhZnJvbVtpbmRleGlkXT17fTsNCiAgICAgICAgICAgIG9ialsibSIgKyBpZF0ucmVsYWZyb20uZGlzcGxheT1kb2N1bWVudC5nZXRFbGVtZW50QnlJZChpZCkuc3R5bGUuZGlzcGxheSAhPT0gJ25vbmUnPydibG9jayc6J25vbmUnOw0KICAgICAgICB9DQogICAgfQ0KICAgIGlmIChyZWxhdG8ubGVuZ3RoICE9PSAwKSB7DQogICAgICAgIG9ialsibSIgKyBpZF0ucmVsYXRvID0ge307DQogICAgICAgIGZvciAodmFyIGkgPSAwOyBpIDwgcmVsYXRvLmxlbmd0aDsgaSsrKSB7DQogICAgICAgICAgICB2YXIgaW5kZXhpZD1yZWxhdG9baV0uaWQ7DQogICAgICAgICAgICB2YXIgZnJvbWlkPWRvY3VtZW50LmdldEVsZW1lbnRCeUlkKGluZGV4aWQpLmdldEF0dHJpYnV0ZSgnZWQ6ZnJvbWlkJyk7DQogICAgICAgICAgICBpZihleHRyYVJlbGFbaW5kZXhpZF0gPT09IHVuZGVmaW5lZCl7DQogICAgICAgICAgICAgICAgZXh0cmFSZWxhW2luZGV4aWRdPXsNCiAgICAgICAgICAgICAgICAgICAgaWQ6aW5kZXhpZCwNCiAgICAgICAgICAgICAgICAgICAgZnJvbWlkOmZyb21pZCwNCiAgICAgICAgICAgICAgICAgICAgdG9pZDppZCwNCiAgICAgICAgICAgICAgICAgICAgaXNDOmZhbHNlDQogICAgICAgICAgICAgICAgfTsNCiAgICAgICAgICAgIH0NCiAgICAgICAgICAgIG9ialsibSIgKyBpZF0ucmVsYXRvW2luZGV4aWRdPXt9Ow0KICAgICAgICAgICAgb2JqWyJtIiArIGlkXS5yZWxhdG8uZGlzcGxheT1kb2N1bWVudC5nZXRFbGVtZW50QnlJZChpZCkuc3R5bGUuZGlzcGxheSAhPT0gJ25vbmUnPydibG9jayc6J25vbmUnOw0KICAgICAgICB9DQogICAgfQ0KICAgIGlmIChjaGlsZHMubGVuZ3RoICE9PSAwKSB7DQogICAgICAgIG9ialsibSIgKyBpZF0uY2hpbGQgPSB7fTsNCiAgICAgICAgaWYgKGRvY3VtZW50LnF1ZXJ5U2VsZWN0b3IoImdbZWRcXDp0b2d0b3BpY2lkPSciICsgaWQgKyAiJ10iKSkgew0KICAgICAgICAgICAgLy8gY29uc29sZS5sb2coZG9jdW1lbnQucXVlcnlTZWxlY3RvcigiZ1tlZFxcOnRvZ3RvcGljaWQ9JyIgKyBpZCArICInXSIpLmNoaWxkTm9kZXNbMF0uZ2V0QXR0cmlidXRlKCd4bGluazpocmVmJykpOw0KICAgICAgICAgICAgdmFyIHRvZyA9IGRvY3VtZW50LnF1ZXJ5U2VsZWN0b3IoImdbZWRcXDp0b2d0b3BpY2lkPSciICsgaWQgKyAiJ10iKS5nZXRFbGVtZW50c0J5VGFnTmFtZSgndXNlJylbMF0uZ2V0QXR0cmlidXRlKCd4bGluazpocmVmJykuc2xpY2UoMSk7DQogICAgICAgICAgICBvYmpbIm0iICsgaWRdLnRvZ3R5cGUgPSB0b2c7DQogICAgICAgIH0NCiAgICAgICAgZm9yICh2YXIgaSA9IDA7IGkgPCBjaGlsZHMubGVuZ3RoOyBpKyspIHsNCiAgICAgICAgICAgIHZhciBjaWQgPSBjaGlsZHNbaV0uaWQ7DQogICAgICAgICAgICBpbml0KGNpZCwgb2JqWyJtIiArIGlkXS5jaGlsZCk7DQogICAgICAgIH0NCiAgICB9DQogICAgaWYgKGNhbGxzLmxlbmd0aCAhPT0gMCkgew0KICAgICAgICBvYmpbIm0iICsgaWRdLmNhbGwgPSB7fTsNCiAgICAgICAgZm9yICh2YXIgaSA9IDA7IGkgPCBjYWxscy5sZW5ndGg7IGkrKykgew0KICAgICAgICAgICAgdmFyIGNpZCA9IGNhbGxzW2ldLmlkOw0KICAgICAgICAgICAgaW5pdChjaWQsIG9ialsibSIgKyBpZF0uY2FsbCk7DQogICAgICAgIH0NCiAgICB9DQogICAgaWYgKGJvdW5kYXJ5Lmxlbmd0aCAhPT0gMCkgew0KICAgICAgICBvYmpbIm0iICsgaWRdLmJvdW5kYXJ5ID0ge307DQogICAgICAgIGZvciAodmFyIGkgPSAwOyBpIDwgYm91bmRhcnkubGVuZ3RoOyBpKyspIHsNCiAgICAgICAgICAgIHZhciBjaWQgPWJvdW5kYXJ5W2ldLmlkOw0KICAgICAgICAgICAgaW5pdChjaWQsIG9ialsibSIgKyBpZF0uYm91bmRhcnkpOw0KICAgICAgICB9DQogICAgfQ0KICAgIGlmIChzdW1tYXJ5Lmxlbmd0aCAhPT0gMCkgew0KICAgICAgICBvYmpbIm0iICsgaWRdLnN1bW1hcnkgPSB7fTsNCiAgICAgICAgZm9yICh2YXIgaSA9IDA7IGkgPCBzdW1tYXJ5Lmxlbmd0aDsgaSsrKSB7DQogICAgICAgICAgICB2YXIgY2lkID0gc3VtbWFyeVtpXS5pZDsNCiAgICAgICAgICAgIGluaXQoY2lkLCBvYmpbIm0iICsgaWRdLnN1bW1hcnkpOw0KICAgICAgICB9DQogICAgfQ0KfQ0KLy8tLWluaXRpYWxpemUNCi8vdG9nZ2xlZGlzcGxheS0tDQp2YXIgY2hhaW5BcnI9W107DQpmdW5jdGlvbiBnZXRjaGFpbihpZCl7DQogICAgY2hhaW5BcnIudW5zaGlmdCgnbScraWQpOw0KICAgIHZhciBwYXJlbnQ9ZG9jdW1lbnQuZ2V0RWxlbWVudEJ5SWQoaWQpLmdldEF0dHJpYnV0ZSgnZWQ6cGFyZW50aWQnKTsNCiAgICBpZighcGFyZW50KXsNCiAgICAgICAgcmV0dXJuOw0KICAgIH0NCiAgICBnZXRjaGFpbihwYXJlbnQpOw0KfQ0KZnVuY3Rpb24gZ2V0b2JqKGlkKSB7DQogICAgY2hhaW5BcnI9W107DQogICAgZ2V0Y2hhaW4oaWQpOw0KICAgIHZhciBtYWluPWNoYWluQXJyWzBdOw0KICAgIGlmKGNoYWluQXJyLmxlbmd0aD4xKXsNCiAgICAgICAgdmFyIG9iaj1kYXRhVHJlZVttYWluXTsNCiAgICAgICAgLy8gY29uc29sZS5sb2coY2hhaW5BcnIpOw0KICAgICAgICBmb3IodmFyIGk9MTtpPGNoYWluQXJyLmxlbmd0aDtpKyspIHsNCiAgICAgICAgICAgIHZhciBhID0gY2hhaW5BcnJbaV07DQogICAgICAgICAgICBmb3IodmFyIGo9MDtqPE9iamVjdC5rZXlzKG9iaikubGVuZ3RoO2orKyl7DQogICAgICAgICAgICAgICAgdmFyIGNvYmo9IG9ialtPYmplY3Qua2V5cyhvYmopW2pdXVthXTsNCiAgICAgICAgICAgICAgICBpZihjb2JqKXsNCiAgICAgICAgICAgICAgICAgICAgb2JqPWNvYmo7DQogICAgICAgICAgICAgICAgICAgIGNvbnRpbnVlDQogICAgICAgICAgICAgICAgfQ0KICAgICAgICAgICAgfQ0KICAgICAgICB9DQogICAgICAgIHJldHVybiBvYmoNCiAgICB9ZWxzZXsNCiAgICAgICAgdmFyIG9iaj1kYXRhVHJlZVttYWluXTsNCiAgICAgICAgcmV0dXJuIG9iag0KICAgIH0NCg0KfQ0KZm9yKHZhciBpPTA7aTxzaGFwZS5sZW5ndGg7aSsrKXsNCiAgICBzaGFwZVtpXS5vbmNsaWNrPWZ1bmN0aW9uICgpIHsNCiAgICAgICAgdmFyIGlkPU51bWJlcih0aGlzLmdldEF0dHJpYnV0ZSgnZWQ6dG9ndG9waWNpZCcpKTsNCiAgICAgICAgdmFyIG9iaj1nZXRvYmooaWQpOw0KDQogICAgICAgIHZhciB0eXBlPW9iai50b2d0eXBlPT09J21pbnVzJz8ncGx1cyc6J21pbnVzJzsNCiAgICAgICAgdmFyIGRpc3BsYXk9b2JqLnRvZ3R5cGU9PT0nbWludXMnPydub25lJzonYmxvY2snOw0KICAgICAgICB0aGlzLmdldEVsZW1lbnRzQnlUYWdOYW1lKCd1c2UnKVswXS5zZXRBdHRyaWJ1dGUoJ3hsaW5rOmhyZWYnLCcjJyt0eXBlKTsNCiAgICAgICAgb2JqLnRvZ3R5cGU9dHlwZTsNCiAgICAgICAgY2hlY2tJRD1vYmo7DQoNCiAgICAgICAgdXRkKG9iaixpZCxkaXNwbGF5KTsNCiAgICAgICAgZXh0cmFSZWxhRmluKCk7DQogICAgfQ0KfQ0KZnVuY3Rpb24gdXRkKG9iaixpZCxzaG93LG9jKSB7DQoNCiAgICB2YXIgcHNob3c9ZG9jdW1lbnQuZ2V0RWxlbWVudEJ5SWQoaWQpLnN0eWxlLmRpc3BsYXkhPT0gJ25vbmUnPydibG9jayc6J25vbmUnOw0KICAgIGlmIChvYmoucmVsYWZyb20pew0KICAgICAgICBpZihvYmoucmVsYWZyb20uZGlzcGxheSE9PSBwc2hvdyl7DQogICAgICAgICAgICB2YXIgcmVsYWZyb21zPU9iamVjdC5rZXlzKG9iai5yZWxhZnJvbSk7DQogICAgICAgICAgICByZWxhZnJvbXMuc3BsaWNlKHJlbGFmcm9tcy5pbmRleE9mKCdkaXNwbGF5JyksMSk7DQogICAgICAgICAgICBmb3IodmFyIGs9MDtrPHJlbGFmcm9tcy5sZW5ndGg7aysrKXsNCiAgICAgICAgICAgICAgICB2YXIgZD1yZWxhZnJvbXNba107DQogICAgICAgICAgICAgICAgZXh0cmFSZWxhW2RdLmlzQz10cnVlOw0KICAgICAgICAgICAgfQ0KICAgICAgICAgICAgb2JqLnJlbGFmcm9tLmRpc3BsYXkgPSBwc2hvdzsNCiAgICAgICAgfQ0KICAgIH0NCiAgICBpZiAob2JqLnJlbGF0byl7DQogICAgICAgIGlmKG9iai5yZWxhdG8uZGlzcGxheSE9PSBwc2hvdyl7DQogICAgICAgICAgICB2YXIgcmVsYXRvcz1PYmplY3Qua2V5cyhvYmoucmVsYXRvKTsNCiAgICAgICAgICAgIHJlbGF0b3Muc3BsaWNlKHJlbGF0b3MuaW5kZXhPZignZGlzcGxheScpLDEpOw0KICAgICAgICAgICAgZm9yKHZhciBrPTA7azxyZWxhdG9zLmxlbmd0aDtrKyspew0KICAgICAgICAgICAgICAgIHZhciBkPXJlbGF0b3Nba107DQogICAgICAgICAgICAgICAgZXh0cmFSZWxhW2RdLmlzQz10cnVlOw0KICAgICAgICAgICAgfQ0KICAgICAgICAgICAgb2JqLnJlbGF0by5kaXNwbGF5ID0gcHNob3c7DQogICAgICAgIH0NCiAgICB9DQogICAgaWYob2JqLmNhbGwpew0KICAgICAgICB2YXIgY2FsbHM9T2JqZWN0LmtleXMob2JqLmNhbGwpOw0KICAgICAgICBpZihjaGVja0lEIT09b2JqKXsNCiAgICAgICAgICAgIGZvcih2YXIgaT0wO2kgPCBjYWxscy5sZW5ndGg7aSsrKXsNCiAgICAgICAgICAgICAgICB2YXIgYT1jYWxsc1tpXS5zbGljZSgxKTsNCiAgICAgICAgICAgICAgICB2YXIgYj1vYmouY2FsbFtjYWxsc1tpXV07DQogICAgICAgICAgICAgICAgdmFyIGM9Yi50b2d0eXBlOw0KICAgICAgICAgICAgICAgIGRvY3VtZW50LmdldEVsZW1lbnRCeUlkKGEpLnN0eWxlLmRpc3BsYXk9c2hvdzsNCiAgICAgICAgICAgICAgICBpZiAoYi5yZWxhZnJvbSYmIWMpew0KICAgICAgICAgICAgICAgICAgICBpZihiLnJlbGFmcm9tLmRpc3BsYXkhPT0gc2hvdyl7DQogICAgICAgICAgICAgICAgICAgICAgICB2YXIgcmVsYWZyb21zPU9iamVjdC5rZXlzKGIucmVsYWZyb20pOw0KICAgICAgICAgICAgICAgICAgICAgICAgcmVsYWZyb21zLnNwbGljZShyZWxhZnJvbXMuaW5kZXhPZignZGlzcGxheScpLDEpOw0KICAgICAgICAgICAgICAgICAgICAgICAgZm9yKHZhciBrPTA7azxyZWxhZnJvbXMubGVuZ3RoO2srKyl7DQogICAgICAgICAgICAgICAgICAgICAgICAgICAgdmFyIGQ9cmVsYWZyb21zW2tdOw0KICAgICAgICAgICAgICAgICAgICAgICAgICAgIGV4dHJhUmVsYVtkXS5pc0M9dHJ1ZTsNCiAgICAgICAgICAgICAgICAgICAgICAgIH0NCiAgICAgICAgICAgICAgICAgICAgICAgIGIucmVsYWZyb20uZGlzcGxheSA9IHNob3c7DQogICAgICAgICAgICAgICAgICAgIH0NCiAgICAgICAgICAgICAgICB9DQogICAgICAgICAgICAgICAgaWYgKGIucmVsYXRvJiYhYyl7DQogICAgICAgICAgICAgICAgICAgIGlmKGIucmVsYXRvLmRpc3BsYXkhPT0gc2hvdyl7DQogICAgICAgICAgICAgICAgICAgICAgICB2YXIgcmVsYXRvcz1PYmplY3Qua2V5cyhiLnJlbGF0byk7DQogICAgICAgICAgICAgICAgICAgICAgICByZWxhdG9zLnNwbGljZShyZWxhdG9zLmluZGV4T2YoJ2Rpc3BsYXknKSwxKTsNCiAgICAgICAgICAgICAgICAgICAgICAgIGZvcih2YXIgaz0wO2s8cmVsYXRvcy5sZW5ndGg7aysrKXsNCiAgICAgICAgICAgICAgICAgICAgICAgICAgICB2YXIgZD1yZWxhdG9zW2tdOw0KICAgICAgICAgICAgICAgICAgICAgICAgICAgIGV4dHJhUmVsYVtkXS5pc0M9dHJ1ZTsNCiAgICAgICAgICAgICAgICAgICAgICAgIH0NCiAgICAgICAgICAgICAgICAgICAgICAgIGIucmVsYXRvLmRpc3BsYXkgPSBzaG93Ow0KICAgICAgICAgICAgICAgICAgICB9DQogICAgICAgICAgICAgICAgfQ0KICAgICAgICAgICAgICAgIGlmKGMpew0KICAgICAgICAgICAgICAgICAgICBkb2N1bWVudC5xdWVyeVNlbGVjdG9yKCJnW2VkXFw6dG9ndG9waWNpZD0nIithKyInXSIpLnN0eWxlLmRpc3BsYXk9c2hvdzsNCiAgICAgICAgICAgICAgICAgICAgaWYoYz09PSdtaW51cycpew0KICAgICAgICAgICAgICAgICAgICAgICAgdXRkKGIsYSxzaG93KQ0KICAgICAgICAgICAgICAgICAgICB9DQogICAgICAgICAgICAgICAgICAgIGlmICgoYi5jYWxsfHxiLmJvdW5kYXJ5fHxiLnN1bW1hcnkpJiZjPT09J3BsdXMnKSB7DQogICAgICAgICAgICAgICAgICAgICAgICB1dGQoYixhLHNob3csdHJ1ZSkNCiAgICAgICAgICAgICAgICAgICAgfQ0KICAgICAgICAgICAgICAgIH0NCiAgICAgICAgICAgICAgICBpZihiLmNhbGwmJiFjKSB7DQogICAgICAgICAgICAgICAgICAgIHV0ZChiLGEsc2hvdyx0cnVlKQ0KICAgICAgICAgICAgICAgIH0NCiAgICAgICAgICAgICAgICBpZiAoYi5zdW1tYXJ5JiYhYykgew0KICAgICAgICAgICAgICAgICAgICB1dGQoYixhLHNob3cpDQogICAgICAgICAgICAgICAgfQ0KICAgICAgICAgICAgICAgIGlmIChiLmJvdW5kYXJ5JiYhYykgew0KICAgICAgICAgICAgICAgICAgICB1dGQoYixhLHNob3cpDQogICAgICAgICAgICAgICAgfQ0KDQogICAgICAgICAgICB9DQogICAgICAgIH0NCiAgICB9DQogICAgaWYob2JqLnN1bW1hcnkpew0KICAgICAgICB2YXIgc3VtbWFyeXM9T2JqZWN0LmtleXMob2JqLnN1bW1hcnkpOw0KICAgICAgICBpZigoY2hlY2tJRCE9PW9iaiYmKG9iai50b2d0eXBlPT09J21pbnVzJ3x8IW9iai50b2d0eXBlKSl8fGNoZWNrSUQ9PT1vYmopew0KICAgICAgICAgICAgZm9yKHZhciBpPTA7aTxzdW1tYXJ5cy5sZW5ndGg7aSsrKXsNCiAgICAgICAgICAgICAgICB2YXIgYT1zdW1tYXJ5c1tpXS5zbGljZSgxKTsNCiAgICAgICAgICAgICAgICB2YXIgYj1vYmouc3VtbWFyeVtzdW1tYXJ5c1tpXV07DQogICAgICAgICAgICAgICAgLy8gY29uc29sZS5sb2coYSk7DQogICAgICAgICAgICAgICAgZG9jdW1lbnQuZ2V0RWxlbWVudEJ5SWQoYSkuc3R5bGUuZGlzcGxheT1zaG93Ow0KLy8gICAgICAgICAgICAgICAgaWYoYyl7DQovLyAgICAgICAgICAgICAgICAgICAgZG9jdW1lbnQucXVlcnlTZWxlY3RvcigiZ1tlZFxcOnRvZ3RvcGljaWQ9JyIrYSsiJ10iKS5zdHlsZS5kaXNwbGF5PXNob3c7DQovLyAgICAgICAgICAgICAgICAgICAgaWYoYz09PSdtaW51cycpew0KLy8gICAgICAgICAgICAgICAgICAgICAgICB1dGQoYixzaG93KQ0KLy8gICAgICAgICAgICAgICAgICAgIH0NCi8vICAgICAgICAgICAgICAgICAgICBpZiAoYi5jYWxsJiZjPT09J3BsdXMnKSB7DQovLyAgICAgICAgICAgICAgICAgICAgICAgIHV0ZChiLHNob3csdHJ1ZSkNCi8vICAgICAgICAgICAgICAgICAgICB9DQovLyAgICAgICAgICAgICAgICB9DQovLyAgICAgICAgICAgICAgICBpZihiLmNhbGwmJiFjKSB7DQovLyAgICAgICAgICAgICAgICAgICAgdXRkKGIsc2hvdyx0cnVlKQ0KLy8gICAgICAgICAgICAgICAgfQ0KICAgICAgICAgICAgICAgIGlmKE9iamVjdC5rZXlzKGIpLmxlbmd0aCE9PTApew0KICAgICAgICAgICAgICAgICAgICB1dGQoYixhLHNob3cpDQogICAgICAgICAgICAgICAgfQ0KICAgICAgICAgICAgfQ0KICAgICAgICB9DQogICAgfQ0KICAgIGlmKG9iai5ib3VuZGFyeSl7DQogICAgICAgIHZhciBib3VuZGFyeXM9T2JqZWN0LmtleXMob2JqLmJvdW5kYXJ5KTsNCiAgICAgICAgaWYoY2hlY2tJRCE9PW9iail7DQogICAgICAgICAgICBmb3IodmFyIGk9MDtpPGJvdW5kYXJ5cy5sZW5ndGg7aSsrKXsNCiAgICAgICAgICAgICAgICB2YXIgYT1ib3VuZGFyeXNbaV0uc2xpY2UoMSk7DQogICAgICAgICAgICAgICAgdmFyIGI9b2JqLmJvdW5kYXJ5W2JvdW5kYXJ5c1tpXV07DQogICAgICAgICAgICAgICAgLy8gY29uc29sZS5sb2coYSk7DQogICAgICAgICAgICAgICAgZG9jdW1lbnQuZ2V0RWxlbWVudEJ5SWQoYSkuc3R5bGUuZGlzcGxheT1zaG93Ow0KLy8gICAgICAgICAgICAgICAgaWYoYyl7DQovLyAgICAgICAgICAgICAgICAgICAgZG9jdW1lbnQucXVlcnlTZWxlY3RvcigiZ1tlZFxcOnRvZ3RvcGljaWQ9JyIrYSsiJ10iKS5zdHlsZS5kaXNwbGF5PXNob3c7DQovLyAgICAgICAgICAgICAgICAgICAgaWYoYz09PSdtaW51cycpew0KLy8gICAgICAgICAgICAgICAgICAgICAgICB1dGQoYixzaG93KQ0KLy8gICAgICAgICAgICAgICAgICAgIH0NCi8vICAgICAgICAgICAgICAgICAgICBpZiAoYi5jYWxsJiZjPT09J3BsdXMnKSB7DQovLyAgICAgICAgICAgICAgICAgICAgICAgIHV0ZChiLHNob3csdHJ1ZSkNCi8vICAgICAgICAgICAgICAgICAgICB9DQovLyAgICAgICAgICAgICAgICB9DQovLyAgICAgICAgICAgICAgICBpZihiLmNhbGwmJiFjKSB7DQovLyAgICAgICAgICAgICAgICAgICAgdXRkKGIsc2hvdyx0cnVlKQ0KLy8gICAgICAgICAgICAgICAgfQ0KICAgICAgICAgICAgICAgIGlmKE9iamVjdC5rZXlzKGIpLmxlbmd0aCE9PTApew0KICAgICAgICAgICAgICAgICAgICB1dGQoYixhLHNob3cpDQogICAgICAgICAgICAgICAgfQ0KICAgICAgICAgICAgfQ0KICAgICAgICB9DQogICAgfQ0KICAgIGlmKCFvYyYmb2JqLmNoaWxkKSB7DQogICAgICAgIHZhciBjaGlsZHMgPSBPYmplY3Qua2V5cyhvYmouY2hpbGQpOw0KICAgICAgICBmb3IgKHZhciBpID0gMDsgaSA8IGNoaWxkcy5sZW5ndGg7IGkrKykgew0KICAgICAgICAgICAgdmFyIGEgPSBjaGlsZHNbaV0uc2xpY2UoMSk7DQogICAgICAgICAgICB2YXIgYiA9IG9iai5jaGlsZFtjaGlsZHNbaV1dOw0KICAgICAgICAgICAgdmFyIGMgPSBiLnRvZ3R5cGU7DQogICAgICAgICAgICBkb2N1bWVudC5nZXRFbGVtZW50QnlJZChhKS5zdHlsZS5kaXNwbGF5ID0gc2hvdzsNCgkJCXZhciB0U1BhdGggPSBkb2N1bWVudC5xdWVyeVNlbGVjdG9yKCJwYXRoW2VkXFw6dG9zdXBlcmlkPSciK2ErIiddIik7DQogICAgICAgICAgICBpZih0U1BhdGgpew0KICAgICAgICAgICAgICAgIHRTUGF0aC5zdHlsZS5kaXNwbGF5ID0gc2hvdzsNCiAgICAgICAgICAgIH0NCiAgICAgICAgICAgIGlmIChiLnJlbGFmcm9tJiYhYyl7DQogICAgICAgICAgICAgICAgaWYoYi5yZWxhZnJvbS5kaXNwbGF5IT09IHNob3cpew0KICAgICAgICAgICAgICAgICAgICB2YXIgcmVsYWZyb21zPU9iamVjdC5rZXlzKGIucmVsYWZyb20pOw0KICAgICAgICAgICAgICAgICAgICByZWxhZnJvbXMuc3BsaWNlKHJlbGFmcm9tcy5pbmRleE9mKCdkaXNwbGF5JyksMSk7DQogICAgICAgICAgICAgICAgICAgIGZvcih2YXIgaz0wO2s8cmVsYWZyb21zLmxlbmd0aDtrKyspew0KICAgICAgICAgICAgICAgICAgICAgICAgdmFyIGQ9cmVsYWZyb21zW2tdOw0KICAgICAgICAgICAgICAgICAgICAgICAgZXh0cmFSZWxhW2RdLmlzQz10cnVlOw0KICAgICAgICAgICAgICAgICAgICB9DQogICAgICAgICAgICAgICAgICAgIGIucmVsYWZyb20uZGlzcGxheSA9IHNob3c7DQogICAgICAgICAgICAgICAgfQ0KICAgICAgICAgICAgfQ0KICAgICAgICAgICAgaWYgKGIucmVsYXRvJiYhYyl7DQogICAgICAgICAgICAgICAgaWYoYi5yZWxhdG8uZGlzcGxheSE9PSBzaG93KXsNCiAgICAgICAgICAgICAgICAgICAgdmFyIHJlbGF0b3M9T2JqZWN0LmtleXMoYi5yZWxhdG8pOw0KICAgICAgICAgICAgICAgICAgICByZWxhdG9zLnNwbGljZShyZWxhdG9zLmluZGV4T2YoJ2Rpc3BsYXknKSwxKTsNCiAgICAgICAgICAgICAgICAgICAgZm9yKHZhciBrPTA7azxyZWxhdG9zLmxlbmd0aDtrKyspew0KICAgICAgICAgICAgICAgICAgICAgICAgdmFyIGQ9cmVsYXRvc1trXTsNCiAgICAgICAgICAgICAgICAgICAgICAgIGV4dHJhUmVsYVtkXS5pc0M9dHJ1ZTsNCiAgICAgICAgICAgICAgICAgICAgfQ0KICAgICAgICAgICAgICAgICAgICBiLnJlbGF0by5kaXNwbGF5ID0gc2hvdzsNCiAgICAgICAgICAgICAgICB9DQogICAgICAgICAgICB9DQogICAgICAgICAgICBpZiAoYykgew0KICAgICAgICAgICAgICAgIGRvY3VtZW50LnF1ZXJ5U2VsZWN0b3IoImdbZWRcXDp0b2d0b3BpY2lkPSciICsgYSArICInXSIpLnN0eWxlLmRpc3BsYXkgPSBzaG93Ow0KICAgICAgICAgICAgICAgIGlmIChjID09PSAnbWludXMnKSB7DQogICAgICAgICAgICAgICAgICAgIHV0ZChiLGEsc2hvdykNCiAgICAgICAgICAgICAgICB9DQogICAgICAgICAgICAgICAgaWYgKChiLmNhbGx8fGIuYm91bmRhcnl8fGIuc3VtbWFyeSkmJmM9PT0ncGx1cycpIHsNCiAgICAgICAgICAgICAgICAgICAgdXRkKGIsYSxzaG93LHRydWUpDQogICAgICAgICAgICAgICAgfQ0KICAgICAgICAgICAgfQ0KICAgICAgICAgICAgaWYgKGIuY2FsbCYmIWMpIHsNCiAgICAgICAgICAgICAgICB1dGQoYixhLHNob3csdHJ1ZSkNCiAgICAgICAgICAgIH0NCiAgICAgICAgICAgIGlmIChiLnN1bW1hcnkmJiFjKSB7DQogICAgICAgICAgICAgICAgdXRkKGIsYSxzaG93KQ0KICAgICAgICAgICAgfQ0KICAgICAgICAgICAgaWYgKGIuYm91bmRhcnkmJiFjKSB7DQogICAgICAgICAgICAgICAgdXRkKGIsYSxzaG93KQ0KICAgICAgICAgICAgfQ0KICAgICAgICB9DQogICAgfQ0KfQ0KDQpmdW5jdGlvbiBleHRyYVJlbGFGaW4oKSB7DQogICAgdmFyIGV4dHJha2V5cz1PYmplY3Qua2V5cyhleHRyYVJlbGEpOw0KICAgIGZvcih2YXIgaT0wO2k8ZXh0cmFrZXlzLmxlbmd0aDtpKyspew0KICAgICAgICB2YXIgZXh0cmFPYmo9ZXh0cmFSZWxhW2V4dHJha2V5c1tpXV07DQogICAgICAgIGlmKGV4dHJhT2JqLmlzQyA9PT0gdHJ1ZSl7DQogICAgICAgICAgICB2YXIgZnNob3c9ZG9jdW1lbnQuZ2V0RWxlbWVudEJ5SWQoZXh0cmFPYmouZnJvbWlkKS5zdHlsZS5kaXNwbGF5ICE9PSdub25lJz8gdHJ1ZTogZmFsc2U7DQogICAgICAgICAgICB2YXIgdHNob3c9ZG9jdW1lbnQuZ2V0RWxlbWVudEJ5SWQoZXh0cmFPYmoudG9pZCkuc3R5bGUuZGlzcGxheSAhPT0nbm9uZSc/IHRydWU6IGZhbHNlOw0KICAgICAgICAgICAgZG9jdW1lbnQuZ2V0RWxlbWVudEJ5SWQoZXh0cmFPYmouaWQpLnN0eWxlLmRpc3BsYXk9ZnNob3cgJiYgdHNob3c/ICdibG9jayc6ICdub25lJzsNCiAgICAgICAgICAgIGV4dHJhUmVsYVtleHRyYWtleXNbaV1dLmlzQyA9IGZhbHNlOw0KICAgICAgICB9DQogICAgfQ0KfQ=='))</script>
  </body>
</html>




