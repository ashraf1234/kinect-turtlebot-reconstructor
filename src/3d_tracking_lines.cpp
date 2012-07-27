<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN" "http://www.w3.org/TR/html4/strict.dtd">
<html lang="en">
<head>
  <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
  <link rel="stylesheet" type="text/css" href="http://code.in.tum.de/indefero/media/idf/css/yui.css" />
  <link rel="stylesheet" type="text/css" href="http://code.in.tum.de/indefero/media/idf/css/style.css" />
  <!--[if lt IE 7]>
  <link rel="stylesheet" type="text/css" href="http://code.in.tum.de/indefero/media/idf/css/ie6.css" />
  <![endif]-->
  <link rel="stylesheet" type="text/css" href="http://code.in.tum.de/indefero/media/idf/css/prettify.css" />
  <title>hausman/3d-tracking-lines/3d_tracking_lines.cpp - seie2011fall Svn Source Tree - </title>
</head>
<body>
<div id="doc3" class="yui-t1">
  <div id="hd">
<h1 class="project-title">seie2011fall</h1>
    <p class="top"><a href="#title" accesskey="2"></a>
<a href="/indefero/index.php//login/">Sign in or create your account</a>
 | <a href="/indefero/index.php//">Project List</a>

| <a href="/indefero/index.php//help/" title="Help and accessibility features">Help</a>
    </p>
<div id="header">
<div id="main-tabs">

  <a accesskey="1" href="/indefero/index.php//p/seie2011fall/">Project Home</a> 
  <a href="/indefero/index.php//p/seie2011fall/downloads/">Downloads</a> 
  <a href="/indefero/index.php//p/seie2011fall/doc/">Documentation</a> 
 <a href="/indefero/index.php//p/seie2011fall/issues/">Issues</a>
 <a href="/indefero/index.php//p/seie2011fall/source/tree/HEAD/" class="active">Source</a>
 <a href="/indefero/index.php//p/seie2011fall/review/">Code Review</a>

</div>


<div id="sub-tabs">
<a class="active" href="/indefero/index.php//p/seie2011fall/source/tree/HEAD/">Source Tree</a> |
<a href="/indefero/index.php//p/seie2011fall/source/changes/HEAD/">Change Log</a>
 |
<a href="/indefero/index.php//p/seie2011fall/source/help/">How To Get The Code</a>
</div>

</div>

	  <h1 class="title" id="title">seie2011fall Svn Source Tree</h1>

  </div>
  <div id="bd">
    <div id="yui-main"> 
      <div class="yui-b">
	<div class="yui-g"> 
          
	  <div class="content">
<h2 class="top"><a href="/indefero/index.php//p/seie2011fall/source/tree/HEAD/">Root</a><span class="sep">/</span><span class="breadcrumb"><a href="/indefero/index.php//p/seie2011fall/source/tree/HEAD/hausman">hausman</a><span class="sep">/</span><a href="/indefero/index.php//p/seie2011fall/source/tree/HEAD/hausman/3d-tracking-lines">3d-tracking-lines</a><span class="sep">/</span><a href="/indefero/index.php//p/seie2011fall/source/tree/HEAD/hausman/3d-tracking-lines/3d_tracking_lines.cpp">3d_tracking_lines.cpp</a></span></h2>

<table class="code" summary=" ">

   
  <tfoot>
    
    
    <tr><th colspan="2">Source at commit <a class="mono" href="/indefero/index.php//p/seie2011fall/source/commit/HEAD/">HEAD</a> created 3 days 17 hours  ago.<br />
        <span class="smaller">By banacer, Location inference guidline textfile added</span>
    </th></tr>
    
  </tfoot>
  
<tbody>
<tr class="c-line"><td class="code-lc" id="L1"><a href="#L1">1</a></td><td class="code mono prettyprint">#include &lt;pcl/tracking/tracking.h&gt;</td></tr>
<tr class="c-line"><td class="code-lc" id="L2"><a href="#L2">2</a></td><td class="code mono prettyprint">#include &lt;pcl/tracking/particle_filter.h&gt;</td></tr>
<tr class="c-line"><td class="code-lc" id="L3"><a href="#L3">3</a></td><td class="code mono prettyprint">#include &lt;pcl/tracking/kld_adaptive_particle_filter_omp.h&gt;</td></tr>
<tr class="c-line"><td class="code-lc" id="L4"><a href="#L4">4</a></td><td class="code mono prettyprint">#include &lt;pcl/tracking/particle_filter_omp.h&gt;</td></tr>
<tr class="c-line"><td class="code-lc" id="L5"><a href="#L5">5</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L6"><a href="#L6">6</a></td><td class="code mono prettyprint">#include &lt;pcl/tracking/coherence.h&gt;</td></tr>
<tr class="c-line"><td class="code-lc" id="L7"><a href="#L7">7</a></td><td class="code mono prettyprint">#include &lt;pcl/tracking/distance_coherence.h&gt;</td></tr>
<tr class="c-line"><td class="code-lc" id="L8"><a href="#L8">8</a></td><td class="code mono prettyprint">#include &lt;pcl/tracking/hsv_color_coherence.h&gt;</td></tr>
<tr class="c-line"><td class="code-lc" id="L9"><a href="#L9">9</a></td><td class="code mono prettyprint">#include &lt;pcl/tracking/normal_coherence.h&gt;</td></tr>
<tr class="c-line"><td class="code-lc" id="L10"><a href="#L10">10</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L11"><a href="#L11">11</a></td><td class="code mono prettyprint">#include &lt;pcl/tracking/approx_nearest_pair_point_cloud_coherence.h&gt;</td></tr>
<tr class="c-line"><td class="code-lc" id="L12"><a href="#L12">12</a></td><td class="code mono prettyprint">#include &lt;pcl/tracking/nearest_pair_point_cloud_coherence.h&gt;</td></tr>
<tr class="c-line"><td class="code-lc" id="L13"><a href="#L13">13</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L14"><a href="#L14">14</a></td><td class="code mono prettyprint">#include &lt;pcl/point_cloud.h&gt;</td></tr>
<tr class="c-line"><td class="code-lc" id="L15"><a href="#L15">15</a></td><td class="code mono prettyprint">#include &lt;pcl/point_types.h&gt;</td></tr>
<tr class="c-line"><td class="code-lc" id="L16"><a href="#L16">16</a></td><td class="code mono prettyprint">#include &lt;pcl/io/openni_grabber.h&gt;</td></tr>
<tr class="c-line"><td class="code-lc" id="L17"><a href="#L17">17</a></td><td class="code mono prettyprint">#include &lt;pcl/console/parse.h&gt;</td></tr>
<tr class="c-line"><td class="code-lc" id="L18"><a href="#L18">18</a></td><td class="code mono prettyprint">#include &lt;pcl/common/time.h&gt;</td></tr>
<tr class="c-line"><td class="code-lc" id="L19"><a href="#L19">19</a></td><td class="code mono prettyprint">#include &lt;pcl/common/centroid.h&gt;</td></tr>
<tr class="c-line"><td class="code-lc" id="L20"><a href="#L20">20</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L21"><a href="#L21">21</a></td><td class="code mono prettyprint">#include &lt;pcl/visualization/cloud_viewer.h&gt;</td></tr>
<tr class="c-line"><td class="code-lc" id="L22"><a href="#L22">22</a></td><td class="code mono prettyprint">#include &lt;pcl/visualization/pcl_visualizer.h&gt;</td></tr>
<tr class="c-line"><td class="code-lc" id="L23"><a href="#L23">23</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L24"><a href="#L24">24</a></td><td class="code mono prettyprint">#include &lt;pcl/io/pcd_io.h&gt;</td></tr>
<tr class="c-line"><td class="code-lc" id="L25"><a href="#L25">25</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L26"><a href="#L26">26</a></td><td class="code mono prettyprint">#include &lt;pcl/filters/passthrough.h&gt;</td></tr>
<tr class="c-line"><td class="code-lc" id="L27"><a href="#L27">27</a></td><td class="code mono prettyprint">#include &lt;pcl/filters/project_inliers.h&gt;</td></tr>
<tr class="c-line"><td class="code-lc" id="L28"><a href="#L28">28</a></td><td class="code mono prettyprint">#include &lt;pcl/filters/voxel_grid.h&gt;</td></tr>
<tr class="c-line"><td class="code-lc" id="L29"><a href="#L29">29</a></td><td class="code mono prettyprint">#include &lt;pcl/filters/approximate_voxel_grid.h&gt;</td></tr>
<tr class="c-line"><td class="code-lc" id="L30"><a href="#L30">30</a></td><td class="code mono prettyprint">#include &lt;pcl/filters/extract_indices.h&gt;</td></tr>
<tr class="c-line"><td class="code-lc" id="L31"><a href="#L31">31</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L32"><a href="#L32">32</a></td><td class="code mono prettyprint">#include &lt;pcl/features/normal_3d.h&gt;</td></tr>
<tr class="c-line"><td class="code-lc" id="L33"><a href="#L33">33</a></td><td class="code mono prettyprint">#include &lt;pcl/features/normal_3d_omp.h&gt;</td></tr>
<tr class="c-line"><td class="code-lc" id="L34"><a href="#L34">34</a></td><td class="code mono prettyprint">#include &lt;pcl/features/integral_image_normal.h&gt;</td></tr>
<tr class="c-line"><td class="code-lc" id="L35"><a href="#L35">35</a></td><td class="code mono prettyprint">#include &lt;pcl/features/boundary.h&gt;</td></tr>
<tr class="c-line"><td class="code-lc" id="L36"><a href="#L36">36</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L37"><a href="#L37">37</a></td><td class="code mono prettyprint">#include &lt;pcl/sample_consensus/method_types.h&gt;</td></tr>
<tr class="c-line"><td class="code-lc" id="L38"><a href="#L38">38</a></td><td class="code mono prettyprint">#include &lt;pcl/sample_consensus/model_types.h&gt;</td></tr>
<tr class="c-line"><td class="code-lc" id="L39"><a href="#L39">39</a></td><td class="code mono prettyprint">#include &lt;pcl/sample_consensus/ransac.h&gt;</td></tr>
<tr class="c-line"><td class="code-lc" id="L40"><a href="#L40">40</a></td><td class="code mono prettyprint">#include &lt;pcl/sample_consensus/sac_model_line.h&gt;</td></tr>
<tr class="c-line"><td class="code-lc" id="L41"><a href="#L41">41</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L42"><a href="#L42">42</a></td><td class="code mono prettyprint">#include &lt;pcl/segmentation/sac_segmentation.h&gt;</td></tr>
<tr class="c-line"><td class="code-lc" id="L43"><a href="#L43">43</a></td><td class="code mono prettyprint">#include &lt;pcl/segmentation/extract_polygonal_prism_data.h&gt;</td></tr>
<tr class="c-line"><td class="code-lc" id="L44"><a href="#L44">44</a></td><td class="code mono prettyprint">#include &lt;pcl/segmentation/extract_clusters.h&gt;</td></tr>
<tr class="c-line"><td class="code-lc" id="L45"><a href="#L45">45</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L46"><a href="#L46">46</a></td><td class="code mono prettyprint">#include &lt;pcl/keypoints/harris_keypoint3D.h&gt;</td></tr>
<tr class="c-line"><td class="code-lc" id="L47"><a href="#L47">47</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L48"><a href="#L48">48</a></td><td class="code mono prettyprint">#include &lt;pcl/surface/convex_hull.h&gt;</td></tr>
<tr class="c-line"><td class="code-lc" id="L49"><a href="#L49">49</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L50"><a href="#L50">50</a></td><td class="code mono prettyprint">#include &lt;pcl/search/pcl_search.h&gt;</td></tr>
<tr class="c-line"><td class="code-lc" id="L51"><a href="#L51">51</a></td><td class="code mono prettyprint">#include &lt;pcl/common/transforms.h&gt;</td></tr>
<tr class="c-line"><td class="code-lc" id="L52"><a href="#L52">52</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L53"><a href="#L53">53</a></td><td class="code mono prettyprint">#include &lt;boost/format.hpp&gt;</td></tr>
<tr class="c-line"><td class="code-lc" id="L54"><a href="#L54">54</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L55"><a href="#L55">55</a></td><td class="code mono prettyprint">#include &lt;fstream&gt;</td></tr>
<tr class="c-line"><td class="code-lc" id="L56"><a href="#L56">56</a></td><td class="code mono prettyprint">#include &lt;iostream&gt;</td></tr>
<tr class="c-line"><td class="code-lc" id="L57"><a href="#L57">57</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L58"><a href="#L58">58</a></td><td class="code mono prettyprint">#include &lt;math.h&gt;</td></tr>
<tr class="c-line"><td class="code-lc" id="L59"><a href="#L59">59</a></td><td class="code mono prettyprint">#include &quot;PrimitivesExtract.cpp&quot;</td></tr>
<tr class="c-line"><td class="code-lc" id="L60"><a href="#L60">60</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L61"><a href="#L61">61</a></td><td class="code mono prettyprint">#define FPS_CALC_BEGIN                          \</td></tr>
<tr class="c-line"><td class="code-lc" id="L62"><a href="#L62">62</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;static double duration = 0;                 \</td></tr>
<tr class="c-line"><td class="code-lc" id="L63"><a href="#L63">63</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;double start_time = pcl::getTime ();        \</td></tr>
<tr class="c-line"><td class="code-lc" id="L64"><a href="#L64">64</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L65"><a href="#L65">65</a></td><td class="code mono prettyprint">#define FPS_CALC_END(_WHAT_)                    \</td></tr>
<tr class="c-line"><td class="code-lc" id="L66"><a href="#L66">66</a></td><td class="code mono prettyprint">&nbsp;&nbsp;{                                             \</td></tr>
<tr class="c-line"><td class="code-lc" id="L67"><a href="#L67">67</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;double end_time = pcl::getTime ();          \</td></tr>
<tr class="c-line"><td class="code-lc" id="L68"><a href="#L68">68</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;static unsigned count = 0;                  \</td></tr>
<tr class="c-line"><td class="code-lc" id="L69"><a href="#L69">69</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;if (++count == 10)                          \</td></tr>
<tr class="c-line"><td class="code-lc" id="L70"><a href="#L70">70</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;{                                           \</td></tr>
<tr class="c-line"><td class="code-lc" id="L71"><a href="#L71">71</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;std::cout &lt;&lt; &quot;Average framerate(&quot;&lt;&lt; _WHAT_ &lt;&lt; &quot;): &quot; &lt;&lt; double(count)/double(duration) &lt;&lt; &quot; Hz&quot; &lt;&lt;  std::endl; \</td></tr>
<tr class="c-line"><td class="code-lc" id="L72"><a href="#L72">72</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;count = 0;                                                        \</td></tr>
<tr class="c-line"><td class="code-lc" id="L73"><a href="#L73">73</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;duration = 0.0;                                                   \</td></tr>
<tr class="c-line"><td class="code-lc" id="L74"><a href="#L74">74</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;}                                           \</td></tr>
<tr class="c-line"><td class="code-lc" id="L75"><a href="#L75">75</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;else                                        \</td></tr>
<tr class="c-line"><td class="code-lc" id="L76"><a href="#L76">76</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;{                                           \</td></tr>
<tr class="c-line"><td class="code-lc" id="L77"><a href="#L77">77</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;duration += end_time - start_time;        \</td></tr>
<tr class="c-line"><td class="code-lc" id="L78"><a href="#L78">78</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;}                                           \</td></tr>
<tr class="c-line"><td class="code-lc" id="L79"><a href="#L79">79</a></td><td class="code mono prettyprint">&nbsp;&nbsp;}</td></tr>
<tr class="c-line"><td class="code-lc" id="L80"><a href="#L80">80</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L81"><a href="#L81">81</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L82"><a href="#L82">82</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L83"><a href="#L83">83</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L84"><a href="#L84">84</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L85"><a href="#L85">85</a></td><td class="code mono prettyprint">using namespace pcl::tracking;</td></tr>
<tr class="c-line"><td class="code-lc" id="L86"><a href="#L86">86</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L87"><a href="#L87">87</a></td><td class="code mono prettyprint">template&lt;typename PointType&gt;</td></tr>
<tr class="c-line"><td class="code-lc" id="L88"><a href="#L88">88</a></td><td class="code mono prettyprint">class OpenNISegmentTracking {</td></tr>
<tr class="c-line"><td class="code-lc" id="L89"><a href="#L89">89</a></td><td class="code mono prettyprint">public:</td></tr>
<tr class="c-line"><td class="code-lc" id="L90"><a href="#L90">90</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;//typedef pcl::PointXYZRGBANormal RefPointType;</td></tr>
<tr class="c-line"><td class="code-lc" id="L91"><a href="#L91">91</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;typedef pcl::PointXYZRGBA RefPointType;</td></tr>
<tr class="c-line"><td class="code-lc" id="L92"><a href="#L92">92</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;//typedef pcl::PointXYZ RefPointType;</td></tr>
<tr class="c-line"><td class="code-lc" id="L93"><a href="#L93">93</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;typedef ParticleXYZRPY ParticleT;</td></tr>
<tr class="c-line"><td class="code-lc" id="L94"><a href="#L94">94</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L95"><a href="#L95">95</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;typedef pcl::PointCloud&lt;PointType&gt; Cloud;</td></tr>
<tr class="c-line"><td class="code-lc" id="L96"><a href="#L96">96</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;typedef pcl::PointCloud&lt;RefPointType&gt; RefCloud;</td></tr>
<tr class="c-line"><td class="code-lc" id="L97"><a href="#L97">97</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;typedef typename RefCloud::Ptr RefCloudPtr;</td></tr>
<tr class="c-line"><td class="code-lc" id="L98"><a href="#L98">98</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;typedef typename RefCloud::ConstPtr RefCloudConstPtr;</td></tr>
<tr class="c-line"><td class="code-lc" id="L99"><a href="#L99">99</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;typedef typename Cloud::Ptr CloudPtr;</td></tr>
<tr class="c-line"><td class="code-lc" id="L100"><a href="#L100">100</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;typedef typename Cloud::ConstPtr CloudConstPtr;</td></tr>
<tr class="c-line"><td class="code-lc" id="L101"><a href="#L101">101</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;//typedef KLDAdaptiveParticleFilterTracker&lt;RefPointType, ParticleT&gt; ParticleFilter;</td></tr>
<tr class="c-line"><td class="code-lc" id="L102"><a href="#L102">102</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;//typedef KLDAdaptiveParticleFilterOMPTracker&lt;RefPointType, ParticleT&gt; ParticleFilter;</td></tr>
<tr class="c-line"><td class="code-lc" id="L103"><a href="#L103">103</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;//typedef ParticleFilterOMPTracker&lt;RefPointType, ParticleT&gt; ParticleFilter;</td></tr>
<tr class="c-line"><td class="code-lc" id="L104"><a href="#L104">104</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;typedef ParticleFilterTracker&lt;RefPointType, ParticleT&gt; ParticleFilter;</td></tr>
<tr class="c-line"><td class="code-lc" id="L105"><a href="#L105">105</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;typedef typename ParticleFilter::CoherencePtr CoherencePtr;</td></tr>
<tr class="c-line"><td class="code-lc" id="L106"><a href="#L106">106</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;typedef typename pcl::search::KdTree&lt;PointType&gt; KdTree;</td></tr>
<tr class="c-line"><td class="code-lc" id="L107"><a href="#L107">107</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;typedef typename KdTree::Ptr KdTreePtr;</td></tr>
<tr class="c-line"><td class="code-lc" id="L108"><a href="#L108">108</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;OpenNISegmentTracking(const std::string&amp; device_id, int thread_nr,</td></tr>
<tr class="c-line"><td class="code-lc" id="L109"><a href="#L109">109</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;double downsampling_grid_size, bool use_convex_hull,</td></tr>
<tr class="c-line"><td class="code-lc" id="L110"><a href="#L110">110</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;bool visualize_non_downsample, bool visualize_particles,</td></tr>
<tr class="c-line"><td class="code-lc" id="L111"><a href="#L111">111</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;bool use_fixed, int trackers_number) :</td></tr>
<tr class="c-line"><td class="code-lc" id="L112"><a href="#L112">112</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;viewer_(&quot;PCL OpenNI Tracking Viewer&quot;), device_id_(device_id), new_cloud_(</td></tr>
<tr class="c-line"><td class="code-lc" id="L113"><a href="#L113">113</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;false), ne_(thread_nr), counter_(0), use_convex_hull_(</td></tr>
<tr class="c-line"><td class="code-lc" id="L114"><a href="#L114">114</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;use_convex_hull), visualize_non_downsample_(</td></tr>
<tr class="c-line"><td class="code-lc" id="L115"><a href="#L115">115</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;visualize_non_downsample), visualize_particles_(</td></tr>
<tr class="c-line"><td class="code-lc" id="L116"><a href="#L116">116</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;visualize_particles), downsampling_grid_size_(</td></tr>
<tr class="c-line"><td class="code-lc" id="L117"><a href="#L117">117</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;downsampling_grid_size) {</td></tr>
<tr class="c-line"><td class="code-lc" id="L118"><a href="#L118">118</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;KdTreePtr tree(new KdTree(false));</td></tr>
<tr class="c-line"><td class="code-lc" id="L119"><a href="#L119">119</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ne_.setSearchMethod(tree);</td></tr>
<tr class="c-line"><td class="code-lc" id="L120"><a href="#L120">120</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ne_.setRadiusSearch(0.03);</td></tr>
<tr class="c-line"><td class="code-lc" id="L121"><a href="#L121">121</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L122"><a href="#L122">122</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;a_file_.open(&quot;poses_final.txt&quot;);</td></tr>
<tr class="c-line"><td class="code-lc" id="L123"><a href="#L123">123</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;//std::vector&lt;double&gt; default_step_covariance = std::vector&lt;double&gt;(6,</td></tr>
<tr class="c-line"><td class="code-lc" id="L124"><a href="#L124">124</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;//        0.015 * 0.015);</td></tr>
<tr class="c-line"><td class="code-lc" id="L125"><a href="#L125">125</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;std::vector&lt;double&gt; default_step_covariance = std::vector&lt;double&gt;(6,</td></tr>
<tr class="c-line"><td class="code-lc" id="L126"><a href="#L126">126</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;0.005 * 0.015);</td></tr>
<tr class="c-line"><td class="code-lc" id="L127"><a href="#L127">127</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;default_step_covariance[3] *= 40.0;</td></tr>
<tr class="c-line"><td class="code-lc" id="L128"><a href="#L128">128</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;default_step_covariance[4] *= 40.0;</td></tr>
<tr class="c-line"><td class="code-lc" id="L129"><a href="#L129">129</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;default_step_covariance[5] *= 40.0;</td></tr>
<tr class="c-line"><td class="code-lc" id="L130"><a href="#L130">130</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L131"><a href="#L131">131</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;step_covariance_ = default_step_covariance;</td></tr>
<tr class="c-line"><td class="code-lc" id="L132"><a href="#L132">132</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L133"><a href="#L133">133</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L134"><a href="#L134">134</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L135"><a href="#L135">135</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;std::vector&lt;double&gt; initial_noise_covariance = std::vector&lt;double&gt;(6,</td></tr>
<tr class="c-line"><td class="code-lc" id="L136"><a href="#L136">136</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;0.00001);</td></tr>
<tr class="c-line"><td class="code-lc" id="L137"><a href="#L137">137</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;std::vector&lt;double&gt; default_initial_mean = std::vector&lt;double&gt;(6, 0.0);</td></tr>
<tr class="c-line"><td class="code-lc" id="L138"><a href="#L138">138</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L139"><a href="#L139">139</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;for (int i = 0; i &lt; trackers_number; i++) {</td></tr>
<tr class="c-line"><td class="code-lc" id="L140"><a href="#L140">140</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L141"><a href="#L141">141</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;if (use_fixed) {</td></tr>
<tr class="c-line"><td class="code-lc" id="L142"><a href="#L142">142</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;boost::shared_ptr&lt;</td></tr>
<tr class="c-line"><td class="code-lc" id="L143"><a href="#L143">143</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ParticleFilterOMPTracker&lt;RefPointType, ParticleT&gt; &gt; tracker(</td></tr>
<tr class="c-line"><td class="code-lc" id="L144"><a href="#L144">144</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;new ParticleFilterOMPTracker&lt;RefPointType, ParticleT&gt;(</td></tr>
<tr class="c-line"><td class="code-lc" id="L145"><a href="#L145">145</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;thread_nr));</td></tr>
<tr class="c-line"><td class="code-lc" id="L146"><a href="#L146">146</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;tracker_ = tracker;</td></tr>
<tr class="c-line"><td class="code-lc" id="L147"><a href="#L147">147</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L148"><a href="#L148">148</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;} else {</td></tr>
<tr class="c-line"><td class="code-lc" id="L149"><a href="#L149">149</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;boost::shared_ptr&lt;</td></tr>
<tr class="c-line"><td class="code-lc" id="L150"><a href="#L150">150</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;KLDAdaptiveParticleFilterOMPTracker&lt;RefPointType,</td></tr>
<tr class="c-line"><td class="code-lc" id="L151"><a href="#L151">151</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ParticleT&gt; &gt; tracker(</td></tr>
<tr class="c-line"><td class="code-lc" id="L152"><a href="#L152">152</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;new KLDAdaptiveParticleFilterOMPTracker&lt;RefPointType,</td></tr>
<tr class="c-line"><td class="code-lc" id="L153"><a href="#L153">153</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ParticleT&gt;(thread_nr));</td></tr>
<tr class="c-line"><td class="code-lc" id="L154"><a href="#L154">154</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;//here</td></tr>
<tr class="c-line"><td class="code-lc" id="L155"><a href="#L155">155</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;//tracker-&gt;setMaximumParticleNum(500);</td></tr>
<tr class="c-line"><td class="code-lc" id="L156"><a href="#L156">156</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;tracker-&gt;setMaximumParticleNum(1000);</td></tr>
<tr class="c-line"><td class="code-lc" id="L157"><a href="#L157">157</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L158"><a href="#L158">158</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;tracker-&gt;setDelta(0.99);</td></tr>
<tr class="c-line"><td class="code-lc" id="L159"><a href="#L159">159</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;tracker-&gt;setEpsilon(0.2);</td></tr>
<tr class="c-line"><td class="code-lc" id="L160"><a href="#L160">160</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ParticleT bin_size;</td></tr>
<tr class="c-line"><td class="code-lc" id="L161"><a href="#L161">161</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;bin_size.x = 0.1;</td></tr>
<tr class="c-line"><td class="code-lc" id="L162"><a href="#L162">162</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;bin_size.y = 0.1;</td></tr>
<tr class="c-line"><td class="code-lc" id="L163"><a href="#L163">163</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;bin_size.z = 0.1;</td></tr>
<tr class="c-line"><td class="code-lc" id="L164"><a href="#L164">164</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;bin_size.roll = 0.1;</td></tr>
<tr class="c-line"><td class="code-lc" id="L165"><a href="#L165">165</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;bin_size.pitch = 0.1;</td></tr>
<tr class="c-line"><td class="code-lc" id="L166"><a href="#L166">166</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;bin_size.yaw = 0.1;</td></tr>
<tr class="c-line"><td class="code-lc" id="L167"><a href="#L167">167</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;tracker-&gt;setBinSize(bin_size);</td></tr>
<tr class="c-line"><td class="code-lc" id="L168"><a href="#L168">168</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;tracker_ = tracker;</td></tr>
<tr class="c-line"><td class="code-lc" id="L169"><a href="#L169">169</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}</td></tr>
<tr class="c-line"><td class="code-lc" id="L170"><a href="#L170">170</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L171"><a href="#L171">171</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;tracker_-&gt;setTrans(Eigen::Affine3f::Identity());</td></tr>
<tr class="c-line"><td class="code-lc" id="L172"><a href="#L172">172</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;tracker_-&gt;setStepNoiseCovariance(default_step_covariance);</td></tr>
<tr class="c-line"><td class="code-lc" id="L173"><a href="#L173">173</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;tracker_-&gt;setInitialNoiseCovariance(initial_noise_covariance);</td></tr>
<tr class="c-line"><td class="code-lc" id="L174"><a href="#L174">174</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;tracker_-&gt;setInitialNoiseMean(default_initial_mean);</td></tr>
<tr class="c-line"><td class="code-lc" id="L175"><a href="#L175">175</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;tracker_-&gt;setIterationNum(1);</td></tr>
<tr class="c-line"><td class="code-lc" id="L176"><a href="#L176">176</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L177"><a href="#L177">177</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L178"><a href="#L178">178</a></td><td class="code mono prettyprint">//        tracker_-&gt;setParticleNum(400);</td></tr>
<tr class="c-line"><td class="code-lc" id="L179"><a href="#L179">179</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;tracker_-&gt;setParticleNum(800);</td></tr>
<tr class="c-line"><td class="code-lc" id="L180"><a href="#L180">180</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L181"><a href="#L181">181</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;tracker_-&gt;setResampleLikelihoodThr(0.00);</td></tr>
<tr class="c-line"><td class="code-lc" id="L182"><a href="#L182">182</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;tracker_-&gt;setUseNormal(false);</td></tr>
<tr class="c-line"><td class="code-lc" id="L183"><a href="#L183">183</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L184"><a href="#L184">184</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;tracker_-&gt;setMotionRatio(0.2);</td></tr>
<tr class="c-line"><td class="code-lc" id="L185"><a href="#L185">185</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L186"><a href="#L186">186</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;// setup coherences</td></tr>
<tr class="c-line"><td class="code-lc" id="L187"><a href="#L187">187</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ApproxNearestPairPointCloudCoherence&lt;RefPointType&gt;::Ptr coherence =</td></tr>
<tr class="c-line"><td class="code-lc" id="L188"><a href="#L188">188</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ApproxNearestPairPointCloudCoherence&lt;RefPointType&gt;::Ptr(</td></tr>
<tr class="c-line"><td class="code-lc" id="L189"><a href="#L189">189</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;new ApproxNearestPairPointCloudCoherence&lt;</td></tr>
<tr class="c-line"><td class="code-lc" id="L190"><a href="#L190">190</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;RefPointType&gt;());</td></tr>
<tr class="c-line"><td class="code-lc" id="L191"><a href="#L191">191</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;// NearestPairPointCloudCoherence&lt;RefPointType&gt;::Ptr coherence = NearestPairPointCloudCoherence&lt;RefPointType&gt;::Ptr</td></tr>
<tr class="c-line"><td class="code-lc" id="L192"><a href="#L192">192</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;//   (new NearestPairPointCloudCoherence&lt;RefPointType&gt; ());</td></tr>
<tr class="c-line"><td class="code-lc" id="L193"><a href="#L193">193</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L194"><a href="#L194">194</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;boost::shared_ptr&lt;DistanceCoherence&lt;RefPointType&gt; &gt; distance_coherence =</td></tr>
<tr class="c-line"><td class="code-lc" id="L195"><a href="#L195">195</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;boost::shared_ptr&lt;DistanceCoherence&lt;RefPointType&gt; &gt;(</td></tr>
<tr class="c-line"><td class="code-lc" id="L196"><a href="#L196">196</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;new DistanceCoherence&lt;RefPointType&gt;());</td></tr>
<tr class="c-line"><td class="code-lc" id="L197"><a href="#L197">197</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;coherence-&gt;addPointCoherence(distance_coherence);</td></tr>
<tr class="c-line"><td class="code-lc" id="L198"><a href="#L198">198</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L199"><a href="#L199">199</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;boost::shared_ptr&lt;HSVColorCoherence&lt;RefPointType&gt; &gt; color_coherence =</td></tr>
<tr class="c-line"><td class="code-lc" id="L200"><a href="#L200">200</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;boost::shared_ptr&lt;HSVColorCoherence&lt;RefPointType&gt; &gt;(</td></tr>
<tr class="c-line"><td class="code-lc" id="L201"><a href="#L201">201</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;new HSVColorCoherence&lt;RefPointType&gt;());</td></tr>
<tr class="c-line"><td class="code-lc" id="L202"><a href="#L202">202</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;color_coherence-&gt;setWeight(0.1);</td></tr>
<tr class="c-line"><td class="code-lc" id="L203"><a href="#L203">203</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;coherence-&gt;addPointCoherence(color_coherence);</td></tr>
<tr class="c-line"><td class="code-lc" id="L204"><a href="#L204">204</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L205"><a href="#L205">205</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;//boost::shared_ptr&lt;pcl::search::KdTree&lt;RefPointType&gt; &gt; search (new pcl::search::KdTree&lt;RefPointType&gt; (false));</td></tr>
<tr class="c-line"><td class="code-lc" id="L206"><a href="#L206">206</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;boost::shared_ptr&lt;pcl::search::Octree&lt;RefPointType&gt; &gt; search(</td></tr>
<tr class="c-line"><td class="code-lc" id="L207"><a href="#L207">207</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;new pcl::search::Octree&lt;RefPointType&gt;(0.01));</td></tr>
<tr class="c-line"><td class="code-lc" id="L208"><a href="#L208">208</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;//boost::shared_ptr&lt;pcl::search::OrganizedNeighbor&lt;RefPointType&gt; &gt; search (new pcl::search::OrganizedNeighbor&lt;RefPointType&gt;);</td></tr>
<tr class="c-line"><td class="code-lc" id="L209"><a href="#L209">209</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;coherence-&gt;setSearchMethod(search);</td></tr>
<tr class="c-line"><td class="code-lc" id="L210"><a href="#L210">210</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;coherence-&gt;setMaximumDistance(0.01);</td></tr>
<tr class="c-line"><td class="code-lc" id="L211"><a href="#L211">211</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;tracker_-&gt;setCloudCoherence(coherence);</td></tr>
<tr class="c-line"><td class="code-lc" id="L212"><a href="#L212">212</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L213"><a href="#L213">213</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;tracker_vector_.push_back(tracker_);</td></tr>
<tr class="c-line"><td class="code-lc" id="L214"><a href="#L214">214</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}</td></tr>
<tr class="c-line"><td class="code-lc" id="L215"><a href="#L215">215</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L216"><a href="#L216">216</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;}</td></tr>
<tr class="c-line"><td class="code-lc" id="L217"><a href="#L217">217</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L218"><a href="#L218">218</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;bool drawParticles(pcl::visualization::PCLVisualizer&amp; viz) {</td></tr>
<tr class="c-line"><td class="code-lc" id="L219"><a href="#L219">219</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L220"><a href="#L220">220</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;unsigned char colormap_[36] = { 255, 0, 0, 0, 255, 0, 0, 0, 255, 255, 255, 0,</td></tr>
<tr class="c-line"><td class="code-lc" id="L221"><a href="#L221">221</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;255, 0, 255, 0, 255, 255, 127, 0, 0, 0, 127, 0, 0, 0, 127, 127, 127, 0,</td></tr>
<tr class="c-line"><td class="code-lc" id="L222"><a href="#L222">222</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;127, 0, 127, 0, 127, 127 };</td></tr>
<tr class="c-line"><td class="code-lc" id="L223"><a href="#L223">223</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L224"><a href="#L224">224</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;for (uint track = 0; track &lt; tracker_vector_.size(); track++) {</td></tr>
<tr class="c-line"><td class="code-lc" id="L225"><a href="#L225">225</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;bool drawParticles = true;</td></tr>
<tr class="c-line"><td class="code-lc" id="L226"><a href="#L226">226</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ParticleFilter::PointCloudStatePtr particles =</td></tr>
<tr class="c-line"><td class="code-lc" id="L227"><a href="#L227">227</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;tracker_vector_[track]-&gt;getParticles();</td></tr>
<tr class="c-line"><td class="code-lc" id="L228"><a href="#L228">228</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;if (particles) {</td></tr>
<tr class="c-line"><td class="code-lc" id="L229"><a href="#L229">229</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;if (visualize_particles_) {</td></tr>
<tr class="c-line"><td class="code-lc" id="L230"><a href="#L230">230</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;pcl::PointCloud&lt;pcl::PointXYZ&gt;::Ptr particle_cloud(</td></tr>
<tr class="c-line"><td class="code-lc" id="L231"><a href="#L231">231</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;new pcl::PointCloud&lt;pcl::PointXYZ&gt;());</td></tr>
<tr class="c-line"><td class="code-lc" id="L232"><a href="#L232">232</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;for (size_t i = 0; i &lt; particles-&gt;points.size(); i++) {</td></tr>
<tr class="c-line"><td class="code-lc" id="L233"><a href="#L233">233</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;pcl::PointXYZ point;</td></tr>
<tr class="c-line"><td class="code-lc" id="L234"><a href="#L234">234</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L235"><a href="#L235">235</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;point.x = particles-&gt;points[i].x;</td></tr>
<tr class="c-line"><td class="code-lc" id="L236"><a href="#L236">236</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;point.y = particles-&gt;points[i].y;</td></tr>
<tr class="c-line"><td class="code-lc" id="L237"><a href="#L237">237</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;point.z = particles-&gt;points[i].z;</td></tr>
<tr class="c-line"><td class="code-lc" id="L238"><a href="#L238">238</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;particle_cloud-&gt;points.push_back(point);</td></tr>
<tr class="c-line"><td class="code-lc" id="L239"><a href="#L239">239</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}</td></tr>
<tr class="c-line"><td class="code-lc" id="L240"><a href="#L240">240</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L241"><a href="#L241">241</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{</td></tr>
<tr class="c-line"><td class="code-lc" id="L242"><a href="#L242">242</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;if (drawParticles) {</td></tr>
<tr class="c-line"><td class="code-lc" id="L243"><a href="#L243">243</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L244"><a href="#L244">244</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;pcl::visualization::PointCloudColorHandlerCustom&lt;</td></tr>
<tr class="c-line"><td class="code-lc" id="L245"><a href="#L245">245</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;pcl::PointXYZ&gt; blue_color(particle_cloud,</td></tr>
<tr class="c-line"><td class="code-lc" id="L246"><a href="#L246">246</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;colormap_[3 * track],</td></tr>
<tr class="c-line"><td class="code-lc" id="L247"><a href="#L247">247</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;colormap_[3 * track + 1],</td></tr>
<tr class="c-line"><td class="code-lc" id="L248"><a href="#L248">248</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;colormap_[3 * track + 2]);</td></tr>
<tr class="c-line"><td class="code-lc" id="L249"><a href="#L249">249</a></td><td class="code mono prettyprint">//                    pcl::visualization::PointCloudColorHandlerCustom&lt;pcl::PointXYZ&gt; blue_color(particle_cloud, 250, 99,71);</td></tr>
<tr class="c-line"><td class="code-lc" id="L250"><a href="#L250">250</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;if (!viz.updatePointCloud(particle_cloud,</td></tr>
<tr class="c-line"><td class="code-lc" id="L251"><a href="#L251">251</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;blue_color, &quot;particle cloud&quot; + track))</td></tr>
<tr class="c-line"><td class="code-lc" id="L252"><a href="#L252">252</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;viz.addPointCloud(particle_cloud, blue_color,</td></tr>
<tr class="c-line"><td class="code-lc" id="L253"><a href="#L253">253</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&quot;particle cloud&quot; + track);</td></tr>
<tr class="c-line"><td class="code-lc" id="L254"><a href="#L254">254</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}</td></tr>
<tr class="c-line"><td class="code-lc" id="L255"><a href="#L255">255</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}</td></tr>
<tr class="c-line"><td class="code-lc" id="L256"><a href="#L256">256</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}</td></tr>
<tr class="c-line"><td class="code-lc" id="L257"><a href="#L257">257</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L258"><a href="#L258">258</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;} else {</td></tr>
<tr class="c-line"><td class="code-lc" id="L259"><a href="#L259">259</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;PCL_WARN(&quot;no particles\n&quot;);</td></tr>
<tr class="c-line"><td class="code-lc" id="L260"><a href="#L260">260</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;return false;</td></tr>
<tr class="c-line"><td class="code-lc" id="L261"><a href="#L261">261</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}</td></tr>
<tr class="c-line"><td class="code-lc" id="L262"><a href="#L262">262</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}</td></tr>
<tr class="c-line"><td class="code-lc" id="L263"><a href="#L263">263</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;return true;</td></tr>
<tr class="c-line"><td class="code-lc" id="L264"><a href="#L264">264</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;}</td></tr>
<tr class="c-line"><td class="code-lc" id="L265"><a href="#L265">265</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L266"><a href="#L266">266</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;void drawResult(pcl::visualization::PCLVisualizer&amp; viz) {</td></tr>
<tr class="c-line"><td class="code-lc" id="L267"><a href="#L267">267</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L268"><a href="#L268">268</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;unsigned char colormap_[36] = { 255, 0, 0, 0, 255, 0, 0, 0, 255, 255, 255, 0,</td></tr>
<tr class="c-line"><td class="code-lc" id="L269"><a href="#L269">269</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;255, 0, 255, 0, 255, 255, 127, 0, 0, 0, 127, 0, 0, 0, 127, 127, 127, 0,</td></tr>
<tr class="c-line"><td class="code-lc" id="L270"><a href="#L270">270</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;127, 0, 127, 0, 127, 127 };</td></tr>
<tr class="c-line"><td class="code-lc" id="L271"><a href="#L271">271</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L272"><a href="#L272">272</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;for (uint track = 0; track &lt; tracker_vector_.size(); track++) {</td></tr>
<tr class="c-line"><td class="code-lc" id="L273"><a href="#L273">273</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L274"><a href="#L274">274</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ParticleXYZRPY result = tracker_vector_[track]-&gt;getResult();</td></tr>
<tr class="c-line"><td class="code-lc" id="L275"><a href="#L275">275</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;bool non_tracking = false;</td></tr>
<tr class="c-line"><td class="code-lc" id="L276"><a href="#L276">276</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;float row, pitch, yaw, x, y, z;</td></tr>
<tr class="c-line"><td class="code-lc" id="L277"><a href="#L277">277</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L278"><a href="#L278">278</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;if (non_tracking) {</td></tr>
<tr class="c-line"><td class="code-lc" id="L279"><a href="#L279">279</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;if (counter_ &lt; 13) {</td></tr>
<tr class="c-line"><td class="code-lc" id="L280"><a href="#L280">280</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L281"><a href="#L281">281</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Eigen::Affine3f transformation =</td></tr>
<tr class="c-line"><td class="code-lc" id="L282"><a href="#L282">282</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;tracker_vector_[track]-&gt;toEigenMatrix(result);</td></tr>
<tr class="c-line"><td class="code-lc" id="L283"><a href="#L283">283</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;// move a little bit for better visualization</td></tr>
<tr class="c-line"><td class="code-lc" id="L284"><a href="#L284">284</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;transformation.translation() += Eigen::Vector3f(0.0, 0.0,</td></tr>
<tr class="c-line"><td class="code-lc" id="L285"><a href="#L285">285</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-0.005);</td></tr>
<tr class="c-line"><td class="code-lc" id="L286"><a href="#L286">286</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;transformation_ = transformation;</td></tr>
<tr class="c-line"><td class="code-lc" id="L287"><a href="#L287">287</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}</td></tr>
<tr class="c-line"><td class="code-lc" id="L288"><a href="#L288">288</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;} else {</td></tr>
<tr class="c-line"><td class="code-lc" id="L289"><a href="#L289">289</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Eigen::Affine3f transformation =</td></tr>
<tr class="c-line"><td class="code-lc" id="L290"><a href="#L290">290</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;tracker_vector_[track]-&gt;toEigenMatrix(result);</td></tr>
<tr class="c-line"><td class="code-lc" id="L291"><a href="#L291">291</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;transformation.translation() += Eigen::Vector3f(0.0, 0.0,</td></tr>
<tr class="c-line"><td class="code-lc" id="L292"><a href="#L292">292</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-0.005);</td></tr>
<tr class="c-line"><td class="code-lc" id="L293"><a href="#L293">293</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;transformation_ = transformation;</td></tr>
<tr class="c-line"><td class="code-lc" id="L294"><a href="#L294">294</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L295"><a href="#L295">295</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L296"><a href="#L296">296</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}</td></tr>
<tr class="c-line"><td class="code-lc" id="L297"><a href="#L297">297</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L298"><a href="#L298">298</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;RefCloudPtr result_cloud(new RefCloud());</td></tr>
<tr class="c-line"><td class="code-lc" id="L299"><a href="#L299">299</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L300"><a href="#L300">300</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;if (!visualize_non_downsample_)</td></tr>
<tr class="c-line"><td class="code-lc" id="L301"><a href="#L301">301</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;pcl::transformPointCloud&lt;RefPointType&gt;(</td></tr>
<tr class="c-line"><td class="code-lc" id="L302"><a href="#L302">302</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*(tracker_vector_[track]-&gt;getReferenceCloud()),</td></tr>
<tr class="c-line"><td class="code-lc" id="L303"><a href="#L303">303</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*result_cloud, transformation_);</td></tr>
<tr class="c-line"><td class="code-lc" id="L304"><a href="#L304">304</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;else</td></tr>
<tr class="c-line"><td class="code-lc" id="L305"><a href="#L305">305</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L306"><a href="#L306">306</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;pcl::transformPointCloud&lt;RefPointType&gt;(</td></tr>
<tr class="c-line"><td class="code-lc" id="L307"><a href="#L307">307</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*(tracker_vector_[track]-&gt;getReferenceCloud()),</td></tr>
<tr class="c-line"><td class="code-lc" id="L308"><a href="#L308">308</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*result_cloud, transformation_);</td></tr>
<tr class="c-line"><td class="code-lc" id="L309"><a href="#L309">309</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L310"><a href="#L310">310</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Eigen::Vector4f center;</td></tr>
<tr class="c-line"><td class="code-lc" id="L311"><a href="#L311">311</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;pcl::compute3DCentroid&lt;RefPointType&gt;(*result_cloud, center);</td></tr>
<tr class="c-line"><td class="code-lc" id="L312"><a href="#L312">312</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L313"><a href="#L313">313</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;std::stringstream ss;</td></tr>
<tr class="c-line"><td class="code-lc" id="L314"><a href="#L314">314</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ss &lt;&lt; track;</td></tr>
<tr class="c-line"><td class="code-lc" id="L315"><a href="#L315">315</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L316"><a href="#L316">316</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;a_file_ &lt;&lt; center[0] &lt;&lt; &quot; &quot; &lt;&lt; center[1] &lt;&lt; &quot; &quot; &lt;&lt; center[2]</td></tr>
<tr class="c-line"><td class="code-lc" id="L317"><a href="#L317">317</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&lt;&lt; std::endl;</td></tr>
<tr class="c-line"><td class="code-lc" id="L318"><a href="#L318">318</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L319"><a href="#L319">319</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L320"><a href="#L320">320</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{</td></tr>
<tr class="c-line"><td class="code-lc" id="L321"><a href="#L321">321</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L322"><a href="#L322">322</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;pcl::visualization::PointCloudColorHandlerCustom&lt;RefPointType&gt; red_color(</td></tr>
<tr class="c-line"><td class="code-lc" id="L323"><a href="#L323">323</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;result_cloud, colormap_[3 * track],</td></tr>
<tr class="c-line"><td class="code-lc" id="L324"><a href="#L324">324</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;colormap_[3 * track + 1], colormap_[3 * track + 2]);</td></tr>
<tr class="c-line"><td class="code-lc" id="L325"><a href="#L325">325</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L326"><a href="#L326">326</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L327"><a href="#L327">327</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;if (!viz.updatePointCloud(result_cloud, red_color, ss.str()))</td></tr>
<tr class="c-line"><td class="code-lc" id="L328"><a href="#L328">328</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;viz.addPointCloud(result_cloud, red_color, ss.str());</td></tr>
<tr class="c-line"><td class="code-lc" id="L329"><a href="#L329">329</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L330"><a href="#L330">330</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;//points' size</td></tr>
<tr class="c-line"><td class="code-lc" id="L331"><a href="#L331">331</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;viz.setPointCloudRenderingProperties(</td></tr>
<tr class="c-line"><td class="code-lc" id="L332"><a href="#L332">332</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 4,</td></tr>
<tr class="c-line"><td class="code-lc" id="L333"><a href="#L333">333</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ss.str());</td></tr>
<tr class="c-line"><td class="code-lc" id="L334"><a href="#L334">334</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L335"><a href="#L335">335</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}</td></tr>
<tr class="c-line"><td class="code-lc" id="L336"><a href="#L336">336</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}</td></tr>
<tr class="c-line"><td class="code-lc" id="L337"><a href="#L337">337</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;}</td></tr>
<tr class="c-line"><td class="code-lc" id="L338"><a href="#L338">338</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L339"><a href="#L339">339</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;void viz_cb(pcl::visualization::PCLVisualizer&amp; viz) {</td></tr>
<tr class="c-line"><td class="code-lc" id="L340"><a href="#L340">340</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;boost::mutex::scoped_lock lock(mtx_);</td></tr>
<tr class="c-line"><td class="code-lc" id="L341"><a href="#L341">341</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L342"><a href="#L342">342</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;if (!cloud_pass_) {</td></tr>
<tr class="c-line"><td class="code-lc" id="L343"><a href="#L343">343</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;boost::this_thread::sleep(boost::posix_time::seconds(1));</td></tr>
<tr class="c-line"><td class="code-lc" id="L344"><a href="#L344">344</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;return;</td></tr>
<tr class="c-line"><td class="code-lc" id="L345"><a href="#L345">345</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}</td></tr>
<tr class="c-line"><td class="code-lc" id="L346"><a href="#L346">346</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L347"><a href="#L347">347</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;if (new_cloud_ &amp;&amp; cloud_pass_downsampled_) {</td></tr>
<tr class="c-line"><td class="code-lc" id="L348"><a href="#L348">348</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;CloudPtr cloud_pass;</td></tr>
<tr class="c-line"><td class="code-lc" id="L349"><a href="#L349">349</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;if (!visualize_non_downsample_)</td></tr>
<tr class="c-line"><td class="code-lc" id="L350"><a href="#L350">350</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cloud_pass = cloud_pass_downsampled_;</td></tr>
<tr class="c-line"><td class="code-lc" id="L351"><a href="#L351">351</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;else</td></tr>
<tr class="c-line"><td class="code-lc" id="L352"><a href="#L352">352</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cloud_pass = cloud_pass_;</td></tr>
<tr class="c-line"><td class="code-lc" id="L353"><a href="#L353">353</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L354"><a href="#L354">354</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;if (!viz.updatePointCloud(cloud_pass, &quot;cloudpass&quot;)) {</td></tr>
<tr class="c-line"><td class="code-lc" id="L355"><a href="#L355">355</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;viz.addPointCloud(cloud_pass, &quot;cloudpass&quot;);</td></tr>
<tr class="c-line"><td class="code-lc" id="L356"><a href="#L356">356</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;viz.resetCameraViewpoint(&quot;cloudpass&quot;);</td></tr>
<tr class="c-line"><td class="code-lc" id="L357"><a href="#L357">357</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}</td></tr>
<tr class="c-line"><td class="code-lc" id="L358"><a href="#L358">358</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}</td></tr>
<tr class="c-line"><td class="code-lc" id="L359"><a href="#L359">359</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L360"><a href="#L360">360</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;if (new_cloud_ &amp;&amp; reference_) {</td></tr>
<tr class="c-line"><td class="code-lc" id="L361"><a href="#L361">361</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;bool ret = drawParticles(viz);</td></tr>
<tr class="c-line"><td class="code-lc" id="L362"><a href="#L362">362</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;if (ret) {</td></tr>
<tr class="c-line"><td class="code-lc" id="L363"><a href="#L363">363</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;drawResult(viz);</td></tr>
<tr class="c-line"><td class="code-lc" id="L364"><a href="#L364">364</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L365"><a href="#L365">365</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;// draw some texts</td></tr>
<tr class="c-line"><td class="code-lc" id="L366"><a href="#L366">366</a></td><td class="code mono prettyprint">//</td></tr>
<tr class="c-line"><td class="code-lc" id="L367"><a href="#L367">367</a></td><td class="code mono prettyprint">//                viz.removeShape(&quot;N&quot;);</td></tr>
<tr class="c-line"><td class="code-lc" id="L368"><a href="#L368">368</a></td><td class="code mono prettyprint">//                viz.addText(</td></tr>
<tr class="c-line"><td class="code-lc" id="L369"><a href="#L369">369</a></td><td class="code mono prettyprint">//                        (boost::format(&quot;number of Reference PointClouds: %d&quot;)</td></tr>
<tr class="c-line"><td class="code-lc" id="L370"><a href="#L370">370</a></td><td class="code mono prettyprint">//                                % tracker_-&gt;getReferenceCloud()-&gt;points.size()).str(),</td></tr>
<tr class="c-line"><td class="code-lc" id="L371"><a href="#L371">371</a></td><td class="code mono prettyprint">//                        10, 20, 20, 1.0, 1.0, 1.0, &quot;N&quot;);</td></tr>
<tr class="c-line"><td class="code-lc" id="L372"><a href="#L372">372</a></td><td class="code mono prettyprint">//</td></tr>
<tr class="c-line"><td class="code-lc" id="L373"><a href="#L373">373</a></td><td class="code mono prettyprint">//                viz.removeShape(&quot;M&quot;);</td></tr>
<tr class="c-line"><td class="code-lc" id="L374"><a href="#L374">374</a></td><td class="code mono prettyprint">//                viz.addText(</td></tr>
<tr class="c-line"><td class="code-lc" id="L375"><a href="#L375">375</a></td><td class="code mono prettyprint">//                        (boost::format(&quot;number of Measured PointClouds:  %d&quot;)</td></tr>
<tr class="c-line"><td class="code-lc" id="L376"><a href="#L376">376</a></td><td class="code mono prettyprint">//                                % cloud_pass_downsampled_-&gt;points.size()).str(),</td></tr>
<tr class="c-line"><td class="code-lc" id="L377"><a href="#L377">377</a></td><td class="code mono prettyprint">//                        10, 40, 20, 1.0, 1.0, 1.0, &quot;M&quot;);</td></tr>
<tr class="c-line"><td class="code-lc" id="L378"><a href="#L378">378</a></td><td class="code mono prettyprint">//</td></tr>
<tr class="c-line"><td class="code-lc" id="L379"><a href="#L379">379</a></td><td class="code mono prettyprint">//                viz.removeShape(&quot;tracking&quot;);</td></tr>
<tr class="c-line"><td class="code-lc" id="L380"><a href="#L380">380</a></td><td class="code mono prettyprint">//                viz.addText(</td></tr>
<tr class="c-line"><td class="code-lc" id="L381"><a href="#L381">381</a></td><td class="code mono prettyprint">//                        (boost::format(&quot;tracking:        %f fps&quot;)</td></tr>
<tr class="c-line"><td class="code-lc" id="L382"><a href="#L382">382</a></td><td class="code mono prettyprint">//                                % (1.0 / tracking_time_)).str(), 10, 60, 20,</td></tr>
<tr class="c-line"><td class="code-lc" id="L383"><a href="#L383">383</a></td><td class="code mono prettyprint">//                        1.0, 1.0, 1.0, &quot;tracking&quot;);</td></tr>
<tr class="c-line"><td class="code-lc" id="L384"><a href="#L384">384</a></td><td class="code mono prettyprint">//</td></tr>
<tr class="c-line"><td class="code-lc" id="L385"><a href="#L385">385</a></td><td class="code mono prettyprint">//                viz.removeShape(&quot;downsampling&quot;);</td></tr>
<tr class="c-line"><td class="code-lc" id="L386"><a href="#L386">386</a></td><td class="code mono prettyprint">//                viz.addText(</td></tr>
<tr class="c-line"><td class="code-lc" id="L387"><a href="#L387">387</a></td><td class="code mono prettyprint">//                        (boost::format(&quot;downsampling:    %f fps&quot;)</td></tr>
<tr class="c-line"><td class="code-lc" id="L388"><a href="#L388">388</a></td><td class="code mono prettyprint">//                                % (1.0 / downsampling_time_)).str(), 10, 80, 20,</td></tr>
<tr class="c-line"><td class="code-lc" id="L389"><a href="#L389">389</a></td><td class="code mono prettyprint">//                        1.0, 1.0, 1.0, &quot;downsampling&quot;);</td></tr>
<tr class="c-line"><td class="code-lc" id="L390"><a href="#L390">390</a></td><td class="code mono prettyprint">//</td></tr>
<tr class="c-line"><td class="code-lc" id="L391"><a href="#L391">391</a></td><td class="code mono prettyprint">//                viz.removeShape(&quot;computation&quot;);</td></tr>
<tr class="c-line"><td class="code-lc" id="L392"><a href="#L392">392</a></td><td class="code mono prettyprint">//                viz.addText(</td></tr>
<tr class="c-line"><td class="code-lc" id="L393"><a href="#L393">393</a></td><td class="code mono prettyprint">//                        (boost::format(&quot;computation:     %f fps&quot;)</td></tr>
<tr class="c-line"><td class="code-lc" id="L394"><a href="#L394">394</a></td><td class="code mono prettyprint">//                                % (1.0 / computation_time_)).str(), 10, 100, 20,</td></tr>
<tr class="c-line"><td class="code-lc" id="L395"><a href="#L395">395</a></td><td class="code mono prettyprint">//                        1.0, 1.0, 1.0, &quot;computation&quot;);</td></tr>
<tr class="c-line"><td class="code-lc" id="L396"><a href="#L396">396</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L397"><a href="#L397">397</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;for (uint track = 0; track &lt; tracker_vector_.size(); track++) {</td></tr>
<tr class="c-line"><td class="code-lc" id="L398"><a href="#L398">398</a></td><td class="code mono prettyprint">//                        tracker_vector_[track]-&gt;getParticles();</td></tr>
<tr class="c-line"><td class="code-lc" id="L399"><a href="#L399">399</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;std::stringstream ss;</td></tr>
<tr class="c-line"><td class="code-lc" id="L400"><a href="#L400">400</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ss &lt;&lt; track;</td></tr>
<tr class="c-line"><td class="code-lc" id="L401"><a href="#L401">401</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L402"><a href="#L402">402</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;viz.removeShape(&quot;particles&quot; + ss.str());</td></tr>
<tr class="c-line"><td class="code-lc" id="L403"><a href="#L403">403</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;viz.addText(</td></tr>
<tr class="c-line"><td class="code-lc" id="L404"><a href="#L404">404</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;(boost::format(&quot;particles:     %d&quot;)</td></tr>
<tr class="c-line"><td class="code-lc" id="L405"><a href="#L405">405</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;% (tracker_vector_[track]-&gt;getParticles()-&gt;points.size())).str(),</td></tr>
<tr class="c-line"><td class="code-lc" id="L406"><a href="#L406">406</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;10, 120 * track, 20, 1.0, 1.0, 1.0,</td></tr>
<tr class="c-line"><td class="code-lc" id="L407"><a href="#L407">407</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&quot;particles&quot; + ss.str());</td></tr>
<tr class="c-line"><td class="code-lc" id="L408"><a href="#L408">408</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}</td></tr>
<tr class="c-line"><td class="code-lc" id="L409"><a href="#L409">409</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L410"><a href="#L410">410</a></td><td class="code mono prettyprint">//                viz.addText(&quot;Particle filtering-based tracking of 3D lines and corners. &quot;,20,60,23,1.0,1.0,1.0,&quot;title&quot;+counter_);</td></tr>
<tr class="c-line"><td class="code-lc" id="L411"><a href="#L411">411</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}</td></tr>
<tr class="c-line"><td class="code-lc" id="L412"><a href="#L412">412</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}</td></tr>
<tr class="c-line"><td class="code-lc" id="L413"><a href="#L413">413</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;new_cloud_ = false;</td></tr>
<tr class="c-line"><td class="code-lc" id="L414"><a href="#L414">414</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;}</td></tr>
<tr class="c-line"><td class="code-lc" id="L415"><a href="#L415">415</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L416"><a href="#L416">416</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;void filterPassThrough(const CloudConstPtr &amp;cloud, Cloud &amp;result) {</td></tr>
<tr class="c-line"><td class="code-lc" id="L417"><a href="#L417">417</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;FPS_CALC_BEGIN;</td></tr>
<tr class="c-line"><td class="code-lc" id="L418"><a href="#L418">418</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;pcl::PassThrough&lt;PointType&gt; pass;</td></tr>
<tr class="c-line"><td class="code-lc" id="L419"><a href="#L419">419</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;pass.setFilterFieldName(&quot;z&quot;);</td></tr>
<tr class="c-line"><td class="code-lc" id="L420"><a href="#L420">420</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;pass.setFilterLimits(0.0, 10.0);</td></tr>
<tr class="c-line"><td class="code-lc" id="L421"><a href="#L421">421</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;//pass.setFilterLimits (0.0, 1.5);</td></tr>
<tr class="c-line"><td class="code-lc" id="L422"><a href="#L422">422</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;//pass.setFilterLimits (0.0, 0.6);</td></tr>
<tr class="c-line"><td class="code-lc" id="L423"><a href="#L423">423</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;pass.setKeepOrganized(false);</td></tr>
<tr class="c-line"><td class="code-lc" id="L424"><a href="#L424">424</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;pass.setInputCloud(cloud);</td></tr>
<tr class="c-line"><td class="code-lc" id="L425"><a href="#L425">425</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;pass.filter(result);</td></tr>
<tr class="c-line"><td class="code-lc" id="L426"><a href="#L426">426</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;FPS_CALC_END(&quot;filterPassThrough&quot;);</td></tr>
<tr class="c-line"><td class="code-lc" id="L427"><a href="#L427">427</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;}</td></tr>
<tr class="c-line"><td class="code-lc" id="L428"><a href="#L428">428</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L429"><a href="#L429">429</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;void euclideanSegment(const CloudConstPtr &amp;cloud,</td></tr>
<tr class="c-line"><td class="code-lc" id="L430"><a href="#L430">430</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;std::vector&lt;pcl::PointIndices&gt; &amp;cluster_indices) {</td></tr>
<tr class="c-line"><td class="code-lc" id="L431"><a href="#L431">431</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;FPS_CALC_BEGIN;</td></tr>
<tr class="c-line"><td class="code-lc" id="L432"><a href="#L432">432</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;pcl::EuclideanClusterExtraction&lt;PointType&gt; ec;</td></tr>
<tr class="c-line"><td class="code-lc" id="L433"><a href="#L433">433</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;KdTreePtr tree(new KdTree());</td></tr>
<tr class="c-line"><td class="code-lc" id="L434"><a href="#L434">434</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L435"><a href="#L435">435</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ec.setClusterTolerance(0.05); // 2cm</td></tr>
<tr class="c-line"><td class="code-lc" id="L436"><a href="#L436">436</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L437"><a href="#L437">437</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ec.setMinClusterSize(50);</td></tr>
<tr class="c-line"><td class="code-lc" id="L438"><a href="#L438">438</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L439"><a href="#L439">439</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ec.setMaxClusterSize(25000);</td></tr>
<tr class="c-line"><td class="code-lc" id="L440"><a href="#L440">440</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ec.setSearchMethod(tree);</td></tr>
<tr class="c-line"><td class="code-lc" id="L441"><a href="#L441">441</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ec.setInputCloud(cloud);</td></tr>
<tr class="c-line"><td class="code-lc" id="L442"><a href="#L442">442</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ec.extract(cluster_indices);</td></tr>
<tr class="c-line"><td class="code-lc" id="L443"><a href="#L443">443</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;FPS_CALC_END(&quot;euclideanSegmentation&quot;);</td></tr>
<tr class="c-line"><td class="code-lc" id="L444"><a href="#L444">444</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;}</td></tr>
<tr class="c-line"><td class="code-lc" id="L445"><a href="#L445">445</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L446"><a href="#L446">446</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;void gridSample(const CloudConstPtr &amp;cloud, Cloud &amp;result,</td></tr>
<tr class="c-line"><td class="code-lc" id="L447"><a href="#L447">447</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;double leaf_size = 0.01) {</td></tr>
<tr class="c-line"><td class="code-lc" id="L448"><a href="#L448">448</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;FPS_CALC_BEGIN;</td></tr>
<tr class="c-line"><td class="code-lc" id="L449"><a href="#L449">449</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;double start = pcl::getTime();</td></tr>
<tr class="c-line"><td class="code-lc" id="L450"><a href="#L450">450</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;pcl::VoxelGrid&lt;PointType&gt; grid;</td></tr>
<tr class="c-line"><td class="code-lc" id="L451"><a href="#L451">451</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;//pcl::ApproximateVoxelGrid&lt;PointType&gt; grid;</td></tr>
<tr class="c-line"><td class="code-lc" id="L452"><a href="#L452">452</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;grid.setLeafSize(leaf_size, leaf_size, leaf_size);</td></tr>
<tr class="c-line"><td class="code-lc" id="L453"><a href="#L453">453</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;grid.setInputCloud(cloud);</td></tr>
<tr class="c-line"><td class="code-lc" id="L454"><a href="#L454">454</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;grid.filter(result);</td></tr>
<tr class="c-line"><td class="code-lc" id="L455"><a href="#L455">455</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;//result = *cloud;</td></tr>
<tr class="c-line"><td class="code-lc" id="L456"><a href="#L456">456</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;double end = pcl::getTime();</td></tr>
<tr class="c-line"><td class="code-lc" id="L457"><a href="#L457">457</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;downsampling_time_ = end - start;</td></tr>
<tr class="c-line"><td class="code-lc" id="L458"><a href="#L458">458</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;FPS_CALC_END(&quot;gridSample&quot;);</td></tr>
<tr class="c-line"><td class="code-lc" id="L459"><a href="#L459">459</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;}</td></tr>
<tr class="c-line"><td class="code-lc" id="L460"><a href="#L460">460</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L461"><a href="#L461">461</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;void gridSampleApprox(const CloudConstPtr &amp;cloud, Cloud &amp;result,</td></tr>
<tr class="c-line"><td class="code-lc" id="L462"><a href="#L462">462</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;double leaf_size = 0.01) {</td></tr>
<tr class="c-line"><td class="code-lc" id="L463"><a href="#L463">463</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;FPS_CALC_BEGIN;</td></tr>
<tr class="c-line"><td class="code-lc" id="L464"><a href="#L464">464</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;double start = pcl::getTime();</td></tr>
<tr class="c-line"><td class="code-lc" id="L465"><a href="#L465">465</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;//pcl::VoxelGrid&lt;PointType&gt; grid;</td></tr>
<tr class="c-line"><td class="code-lc" id="L466"><a href="#L466">466</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;pcl::ApproximateVoxelGrid&lt;PointType&gt; grid;</td></tr>
<tr class="c-line"><td class="code-lc" id="L467"><a href="#L467">467</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;grid.setLeafSize(leaf_size, leaf_size, leaf_size);</td></tr>
<tr class="c-line"><td class="code-lc" id="L468"><a href="#L468">468</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;grid.setInputCloud(cloud);</td></tr>
<tr class="c-line"><td class="code-lc" id="L469"><a href="#L469">469</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;grid.filter(result);</td></tr>
<tr class="c-line"><td class="code-lc" id="L470"><a href="#L470">470</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;//result = *cloud;</td></tr>
<tr class="c-line"><td class="code-lc" id="L471"><a href="#L471">471</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;double end = pcl::getTime();</td></tr>
<tr class="c-line"><td class="code-lc" id="L472"><a href="#L472">472</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;downsampling_time_ = end - start;</td></tr>
<tr class="c-line"><td class="code-lc" id="L473"><a href="#L473">473</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;FPS_CALC_END(&quot;gridSample&quot;);</td></tr>
<tr class="c-line"><td class="code-lc" id="L474"><a href="#L474">474</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;}</td></tr>
<tr class="c-line"><td class="code-lc" id="L475"><a href="#L475">475</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L476"><a href="#L476">476</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;void planeSegmentation(const CloudConstPtr &amp;cloud,</td></tr>
<tr class="c-line"><td class="code-lc" id="L477"><a href="#L477">477</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;pcl::ModelCoefficients &amp;coefficients, pcl::PointIndices &amp;inliers) {</td></tr>
<tr class="c-line"><td class="code-lc" id="L478"><a href="#L478">478</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;FPS_CALC_BEGIN;</td></tr>
<tr class="c-line"><td class="code-lc" id="L479"><a href="#L479">479</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;pcl::SACSegmentation&lt;PointType&gt; seg;</td></tr>
<tr class="c-line"><td class="code-lc" id="L480"><a href="#L480">480</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;seg.setOptimizeCoefficients(true);</td></tr>
<tr class="c-line"><td class="code-lc" id="L481"><a href="#L481">481</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;seg.setModelType(pcl::SACMODEL_PLANE);</td></tr>
<tr class="c-line"><td class="code-lc" id="L482"><a href="#L482">482</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;seg.setMethodType(pcl::SAC_RANSAC);</td></tr>
<tr class="c-line"><td class="code-lc" id="L483"><a href="#L483">483</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;seg.setMaxIterations(1000);</td></tr>
<tr class="c-line"><td class="code-lc" id="L484"><a href="#L484">484</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;seg.setDistanceThreshold(0.03);</td></tr>
<tr class="c-line"><td class="code-lc" id="L485"><a href="#L485">485</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;seg.setInputCloud(cloud);</td></tr>
<tr class="c-line"><td class="code-lc" id="L486"><a href="#L486">486</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;seg.segment(inliers, coefficients);</td></tr>
<tr class="c-line"><td class="code-lc" id="L487"><a href="#L487">487</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;FPS_CALC_END(&quot;planeSegmentation&quot;);</td></tr>
<tr class="c-line"><td class="code-lc" id="L488"><a href="#L488">488</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;}</td></tr>
<tr class="c-line"><td class="code-lc" id="L489"><a href="#L489">489</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L490"><a href="#L490">490</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;void planeProjection(const CloudConstPtr &amp;cloud, Cloud &amp;result,</td></tr>
<tr class="c-line"><td class="code-lc" id="L491"><a href="#L491">491</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;const pcl::ModelCoefficients::ConstPtr &amp;coefficients) {</td></tr>
<tr class="c-line"><td class="code-lc" id="L492"><a href="#L492">492</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;FPS_CALC_BEGIN;</td></tr>
<tr class="c-line"><td class="code-lc" id="L493"><a href="#L493">493</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;pcl::ProjectInliers&lt;PointType&gt; proj;</td></tr>
<tr class="c-line"><td class="code-lc" id="L494"><a href="#L494">494</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;proj.setModelType(pcl::SACMODEL_PLANE);</td></tr>
<tr class="c-line"><td class="code-lc" id="L495"><a href="#L495">495</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;proj.setInputCloud(cloud);</td></tr>
<tr class="c-line"><td class="code-lc" id="L496"><a href="#L496">496</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;proj.setModelCoefficients(coefficients);</td></tr>
<tr class="c-line"><td class="code-lc" id="L497"><a href="#L497">497</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;proj.filter(result);</td></tr>
<tr class="c-line"><td class="code-lc" id="L498"><a href="#L498">498</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;FPS_CALC_END(&quot;planeProjection&quot;);</td></tr>
<tr class="c-line"><td class="code-lc" id="L499"><a href="#L499">499</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;}</td></tr>
<tr class="c-line"><td class="code-lc" id="L500"><a href="#L500">500</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L501"><a href="#L501">501</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;void convexHull(const CloudConstPtr &amp;cloud, Cloud &amp;result,</td></tr>
<tr class="c-line"><td class="code-lc" id="L502"><a href="#L502">502</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;std::vector&lt;pcl::Vertices&gt; &amp;hull_vertices) {</td></tr>
<tr class="c-line"><td class="code-lc" id="L503"><a href="#L503">503</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;FPS_CALC_BEGIN;</td></tr>
<tr class="c-line"><td class="code-lc" id="L504"><a href="#L504">504</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;pcl::ConvexHull&lt;PointType&gt; chull;</td></tr>
<tr class="c-line"><td class="code-lc" id="L505"><a href="#L505">505</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;chull.setInputCloud(cloud);</td></tr>
<tr class="c-line"><td class="code-lc" id="L506"><a href="#L506">506</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;chull.reconstruct(*cloud_hull_, hull_vertices);</td></tr>
<tr class="c-line"><td class="code-lc" id="L507"><a href="#L507">507</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;FPS_CALC_END(&quot;convexHull&quot;);</td></tr>
<tr class="c-line"><td class="code-lc" id="L508"><a href="#L508">508</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;}</td></tr>
<tr class="c-line"><td class="code-lc" id="L509"><a href="#L509">509</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L510"><a href="#L510">510</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;void normalEstimation(const CloudConstPtr &amp;cloud,</td></tr>
<tr class="c-line"><td class="code-lc" id="L511"><a href="#L511">511</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;pcl::PointCloud&lt;pcl::Normal&gt; &amp;result) {</td></tr>
<tr class="c-line"><td class="code-lc" id="L512"><a href="#L512">512</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;FPS_CALC_BEGIN;</td></tr>
<tr class="c-line"><td class="code-lc" id="L513"><a href="#L513">513</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ne_.setInputCloud(cloud);</td></tr>
<tr class="c-line"><td class="code-lc" id="L514"><a href="#L514">514</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ne_.compute(result);</td></tr>
<tr class="c-line"><td class="code-lc" id="L515"><a href="#L515">515</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;FPS_CALC_END(&quot;normalEstimation&quot;);</td></tr>
<tr class="c-line"><td class="code-lc" id="L516"><a href="#L516">516</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;}</td></tr>
<tr class="c-line"><td class="code-lc" id="L517"><a href="#L517">517</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L518"><a href="#L518">518</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;void tracking(const RefCloudConstPtr &amp;cloud) {</td></tr>
<tr class="c-line"><td class="code-lc" id="L519"><a href="#L519">519</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;double start = pcl::getTime();</td></tr>
<tr class="c-line"><td class="code-lc" id="L520"><a href="#L520">520</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;FPS_CALC_BEGIN;</td></tr>
<tr class="c-line"><td class="code-lc" id="L521"><a href="#L521">521</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;for (uint track = 0; track &lt; tracker_vector_.size(); track++) {</td></tr>
<tr class="c-line"><td class="code-lc" id="L522"><a href="#L522">522</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L523"><a href="#L523">523</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;tracker_vector_[track]-&gt;setInputCloud(cloud);</td></tr>
<tr class="c-line"><td class="code-lc" id="L524"><a href="#L524">524</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;tracker_vector_[track]-&gt;compute();</td></tr>
<tr class="c-line"><td class="code-lc" id="L525"><a href="#L525">525</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L526"><a href="#L526">526</a></td><td class="code mono prettyprint">//        tracker_-&gt;setInputCloud(cloud);</td></tr>
<tr class="c-line"><td class="code-lc" id="L527"><a href="#L527">527</a></td><td class="code mono prettyprint">//        tracker_-&gt;compute();</td></tr>
<tr class="c-line"><td class="code-lc" id="L528"><a href="#L528">528</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}</td></tr>
<tr class="c-line"><td class="code-lc" id="L529"><a href="#L529">529</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;double end = pcl::getTime();</td></tr>
<tr class="c-line"><td class="code-lc" id="L530"><a href="#L530">530</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;FPS_CALC_END(&quot;tracking&quot;);</td></tr>
<tr class="c-line"><td class="code-lc" id="L531"><a href="#L531">531</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;tracking_time_ = end - start;</td></tr>
<tr class="c-line"><td class="code-lc" id="L532"><a href="#L532">532</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L533"><a href="#L533">533</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;}</td></tr>
<tr class="c-line"><td class="code-lc" id="L534"><a href="#L534">534</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L535"><a href="#L535">535</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;void addNormalToCloud(const CloudConstPtr &amp;cloud,</td></tr>
<tr class="c-line"><td class="code-lc" id="L536"><a href="#L536">536</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;const pcl::PointCloud&lt;pcl::Normal&gt;::ConstPtr &amp;normals,</td></tr>
<tr class="c-line"><td class="code-lc" id="L537"><a href="#L537">537</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;RefCloud &amp;result) {</td></tr>
<tr class="c-line"><td class="code-lc" id="L538"><a href="#L538">538</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;result.width = cloud-&gt;width;</td></tr>
<tr class="c-line"><td class="code-lc" id="L539"><a href="#L539">539</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;result.height = cloud-&gt;height;</td></tr>
<tr class="c-line"><td class="code-lc" id="L540"><a href="#L540">540</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;result.is_dense = cloud-&gt;is_dense;</td></tr>
<tr class="c-line"><td class="code-lc" id="L541"><a href="#L541">541</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;for (size_t i = 0; i &lt; cloud-&gt;points.size(); i++) {</td></tr>
<tr class="c-line"><td class="code-lc" id="L542"><a href="#L542">542</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;RefPointType point;</td></tr>
<tr class="c-line"><td class="code-lc" id="L543"><a href="#L543">543</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;point.x = cloud-&gt;points[i].x;</td></tr>
<tr class="c-line"><td class="code-lc" id="L544"><a href="#L544">544</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;point.y = cloud-&gt;points[i].y;</td></tr>
<tr class="c-line"><td class="code-lc" id="L545"><a href="#L545">545</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;point.z = cloud-&gt;points[i].z;</td></tr>
<tr class="c-line"><td class="code-lc" id="L546"><a href="#L546">546</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;point.rgba = cloud-&gt;points[i].rgba;</td></tr>
<tr class="c-line"><td class="code-lc" id="L547"><a href="#L547">547</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;// point.normal[0] = normals-&gt;points[i].normal[0];</td></tr>
<tr class="c-line"><td class="code-lc" id="L548"><a href="#L548">548</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;// point.normal[1] = normals-&gt;points[i].normal[1];</td></tr>
<tr class="c-line"><td class="code-lc" id="L549"><a href="#L549">549</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;// point.normal[2] = normals-&gt;points[i].normal[2];</td></tr>
<tr class="c-line"><td class="code-lc" id="L550"><a href="#L550">550</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;result.points.push_back(point);</td></tr>
<tr class="c-line"><td class="code-lc" id="L551"><a href="#L551">551</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}</td></tr>
<tr class="c-line"><td class="code-lc" id="L552"><a href="#L552">552</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;}</td></tr>
<tr class="c-line"><td class="code-lc" id="L553"><a href="#L553">553</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L554"><a href="#L554">554</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;void extractNonPlanePoints(const CloudConstPtr &amp;cloud,</td></tr>
<tr class="c-line"><td class="code-lc" id="L555"><a href="#L555">555</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;const CloudConstPtr &amp;cloud_hull, Cloud &amp;result) {</td></tr>
<tr class="c-line"><td class="code-lc" id="L556"><a href="#L556">556</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;pcl::ExtractPolygonalPrismData&lt;PointType&gt; polygon_extract;</td></tr>
<tr class="c-line"><td class="code-lc" id="L557"><a href="#L557">557</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;pcl::PointIndices::Ptr inliers_polygon(new pcl::PointIndices());</td></tr>
<tr class="c-line"><td class="code-lc" id="L558"><a href="#L558">558</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;polygon_extract.setHeightLimits(0.01, 10.0);</td></tr>
<tr class="c-line"><td class="code-lc" id="L559"><a href="#L559">559</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;polygon_extract.setInputPlanarHull(cloud_hull);</td></tr>
<tr class="c-line"><td class="code-lc" id="L560"><a href="#L560">560</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;polygon_extract.setInputCloud(cloud);</td></tr>
<tr class="c-line"><td class="code-lc" id="L561"><a href="#L561">561</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;polygon_extract.segment(*inliers_polygon);</td></tr>
<tr class="c-line"><td class="code-lc" id="L562"><a href="#L562">562</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{</td></tr>
<tr class="c-line"><td class="code-lc" id="L563"><a href="#L563">563</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;pcl::ExtractIndices&lt;PointType&gt; extract_positive;</td></tr>
<tr class="c-line"><td class="code-lc" id="L564"><a href="#L564">564</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;extract_positive.setNegative(false);</td></tr>
<tr class="c-line"><td class="code-lc" id="L565"><a href="#L565">565</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;extract_positive.setInputCloud(cloud);</td></tr>
<tr class="c-line"><td class="code-lc" id="L566"><a href="#L566">566</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;extract_positive.setIndices(inliers_polygon);</td></tr>
<tr class="c-line"><td class="code-lc" id="L567"><a href="#L567">567</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;extract_positive.filter(result);</td></tr>
<tr class="c-line"><td class="code-lc" id="L568"><a href="#L568">568</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}</td></tr>
<tr class="c-line"><td class="code-lc" id="L569"><a href="#L569">569</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;}</td></tr>
<tr class="c-line"><td class="code-lc" id="L570"><a href="#L570">570</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L571"><a href="#L571">571</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;void removeZeroPoints(const CloudConstPtr &amp;cloud, Cloud &amp;result) {</td></tr>
<tr class="c-line"><td class="code-lc" id="L572"><a href="#L572">572</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;for (size_t i = 0; i &lt; cloud-&gt;points.size(); i++) {</td></tr>
<tr class="c-line"><td class="code-lc" id="L573"><a href="#L573">573</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;PointType point = cloud-&gt;points[i];</td></tr>
<tr class="c-line"><td class="code-lc" id="L574"><a href="#L574">574</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;if (!(fabs(point.x) &lt; 0.01 &amp;&amp; fabs(point.y) &lt; 0.01</td></tr>
<tr class="c-line"><td class="code-lc" id="L575"><a href="#L575">575</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&amp;&amp; fabs(point.z) &lt; 0.01) &amp;&amp; !pcl_isnan(point.x)</td></tr>
<tr class="c-line"><td class="code-lc" id="L576"><a href="#L576">576</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&amp;&amp; !pcl_isnan(point.y) &amp;&amp; !pcl_isnan(point.z))</td></tr>
<tr class="c-line"><td class="code-lc" id="L577"><a href="#L577">577</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;result.points.push_back(point);</td></tr>
<tr class="c-line"><td class="code-lc" id="L578"><a href="#L578">578</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}</td></tr>
<tr class="c-line"><td class="code-lc" id="L579"><a href="#L579">579</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L580"><a href="#L580">580</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;result.width = result.points.size();</td></tr>
<tr class="c-line"><td class="code-lc" id="L581"><a href="#L581">581</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;result.height = 1;</td></tr>
<tr class="c-line"><td class="code-lc" id="L582"><a href="#L582">582</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;result.is_dense = true;</td></tr>
<tr class="c-line"><td class="code-lc" id="L583"><a href="#L583">583</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;}</td></tr>
<tr class="c-line"><td class="code-lc" id="L584"><a href="#L584">584</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L585"><a href="#L585">585</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;void extractSegmentCluster(const CloudConstPtr &amp;cloud,</td></tr>
<tr class="c-line"><td class="code-lc" id="L586"><a href="#L586">586</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;const std::vector&lt;pcl::PointIndices&gt; cluster_indices,</td></tr>
<tr class="c-line"><td class="code-lc" id="L587"><a href="#L587">587</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;const int segment_index, Cloud &amp;result) {</td></tr>
<tr class="c-line"><td class="code-lc" id="L588"><a href="#L588">588</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;pcl::PointIndices segmented_indices = cluster_indices[segment_index];</td></tr>
<tr class="c-line"><td class="code-lc" id="L589"><a href="#L589">589</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;for (size_t i = 0; i &lt; segmented_indices.indices.size(); i++) {</td></tr>
<tr class="c-line"><td class="code-lc" id="L590"><a href="#L590">590</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;PointType point = cloud-&gt;points[segmented_indices.indices[i]];</td></tr>
<tr class="c-line"><td class="code-lc" id="L591"><a href="#L591">591</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;result.points.push_back(point);</td></tr>
<tr class="c-line"><td class="code-lc" id="L592"><a href="#L592">592</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}</td></tr>
<tr class="c-line"><td class="code-lc" id="L593"><a href="#L593">593</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;result.width = result.points.size();</td></tr>
<tr class="c-line"><td class="code-lc" id="L594"><a href="#L594">594</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;result.height = 1;</td></tr>
<tr class="c-line"><td class="code-lc" id="L595"><a href="#L595">595</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;result.is_dense = true;</td></tr>
<tr class="c-line"><td class="code-lc" id="L596"><a href="#L596">596</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;}</td></tr>
<tr class="c-line"><td class="code-lc" id="L597"><a href="#L597">597</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L598"><a href="#L598">598</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;void cloud_cb(const CloudConstPtr &amp;cloud) {</td></tr>
<tr class="c-line"><td class="code-lc" id="L599"><a href="#L599">599</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;boost::mutex::scoped_lock lock(mtx_);</td></tr>
<tr class="c-line"><td class="code-lc" id="L600"><a href="#L600">600</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;double start = pcl::getTime();</td></tr>
<tr class="c-line"><td class="code-lc" id="L601"><a href="#L601">601</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;FPS_CALC_BEGIN;</td></tr>
<tr class="c-line"><td class="code-lc" id="L602"><a href="#L602">602</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;bool online = true;</td></tr>
<tr class="c-line"><td class="code-lc" id="L603"><a href="#L603">603</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L604"><a href="#L604">604</a></td><td class="code mono prettyprint">//        std::cerr&lt;&lt;&quot;cloud height: &quot;&lt;&lt;cloud-&gt;height&lt;&lt;std::endl;</td></tr>
<tr class="c-line"><td class="code-lc" id="L605"><a href="#L605">605</a></td><td class="code mono prettyprint">//        std::cerr&lt;&lt;&quot;cloud width: &quot;&lt;&lt;cloud-&gt;width&lt;&lt;std::endl;</td></tr>
<tr class="c-line"><td class="code-lc" id="L606"><a href="#L606">606</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L607"><a href="#L607">607</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;if (online)</td></tr>
<tr class="c-line"><td class="code-lc" id="L608"><a href="#L608">608</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cloud_pass_.reset(new Cloud);</td></tr>
<tr class="c-line"><td class="code-lc" id="L609"><a href="#L609">609</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L610"><a href="#L610">610</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cloud_pass_downsampled_.reset(new Cloud);</td></tr>
<tr class="c-line"><td class="code-lc" id="L611"><a href="#L611">611</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;pcl::ModelCoefficients::Ptr coefficients(new pcl::ModelCoefficients());</td></tr>
<tr class="c-line"><td class="code-lc" id="L612"><a href="#L612">612</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;pcl::PointIndices::Ptr inliers(new pcl::PointIndices());</td></tr>
<tr class="c-line"><td class="code-lc" id="L613"><a href="#L613">613</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L614"><a href="#L614">614</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;if (!online) {</td></tr>
<tr class="c-line"><td class="code-lc" id="L615"><a href="#L615">615</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L616"><a href="#L616">616</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;if (counter_ == 0) {</td></tr>
<tr class="c-line"><td class="code-lc" id="L617"><a href="#L617">617</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L618"><a href="#L618">618</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cloud_pass_.reset(new Cloud);</td></tr>
<tr class="c-line"><td class="code-lc" id="L619"><a href="#L619">619</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L620"><a href="#L620">620</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;pcl::PointCloud&lt;pcl::PointXYZRGB&gt;::Ptr cloud23(</td></tr>
<tr class="c-line"><td class="code-lc" id="L621"><a href="#L621">621</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;new pcl::PointCloud&lt;pcl::PointXYZRGB&gt;);</td></tr>
<tr class="c-line"><td class="code-lc" id="L622"><a href="#L622">622</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;//CloudPtr cloud23(new CloudPtr);</td></tr>
<tr class="c-line"><td class="code-lc" id="L623"><a href="#L623">623</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L624"><a href="#L624">624</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;if (pcl::io::loadPCDFile&lt;pcl::PointXYZRGB&gt;(&quot;cloud1.pcd&quot;,</td></tr>
<tr class="c-line"><td class="code-lc" id="L625"><a href="#L625">625</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*cloud23) == -1) //* load the file</td></tr>
<tr class="c-line"><td class="code-lc" id="L626"><a href="#L626">626</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{</td></tr>
<tr class="c-line"><td class="code-lc" id="L627"><a href="#L627">627</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;PCL_ERROR(&quot;Couldn't read file test_pcd.pcd \n&quot;);</td></tr>
<tr class="c-line"><td class="code-lc" id="L628"><a href="#L628">628</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}</td></tr>
<tr class="c-line"><td class="code-lc" id="L629"><a href="#L629">629</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L630"><a href="#L630">630</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;CloudPtr cloud22(new Cloud);</td></tr>
<tr class="c-line"><td class="code-lc" id="L631"><a href="#L631">631</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L632"><a href="#L632">632</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;pcl::copyPointCloud(*cloud23, *cloud22);</td></tr>
<tr class="c-line"><td class="code-lc" id="L633"><a href="#L633">633</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L634"><a href="#L634">634</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;filterPassThrough(cloud22, *cloud_pass_);</td></tr>
<tr class="c-line"><td class="code-lc" id="L635"><a href="#L635">635</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L636"><a href="#L636">636</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}</td></tr>
<tr class="c-line"><td class="code-lc" id="L637"><a href="#L637">637</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}</td></tr>
<tr class="c-line"><td class="code-lc" id="L638"><a href="#L638">638</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L639"><a href="#L639">639</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;if (online)</td></tr>
<tr class="c-line"><td class="code-lc" id="L640"><a href="#L640">640</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;filterPassThrough(cloud, *cloud_pass_);</td></tr>
<tr class="c-line"><td class="code-lc" id="L641"><a href="#L641">641</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L642"><a href="#L642">642</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;if (counter_ &lt; 10) {</td></tr>
<tr class="c-line"><td class="code-lc" id="L643"><a href="#L643">643</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;gridSample(cloud_pass_, *cloud_pass_downsampled_,</td></tr>
<tr class="c-line"><td class="code-lc" id="L644"><a href="#L644">644</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;downsampling_grid_size_);</td></tr>
<tr class="c-line"><td class="code-lc" id="L645"><a href="#L645">645</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;} else if (counter_ == 10) {</td></tr>
<tr class="c-line"><td class="code-lc" id="L646"><a href="#L646">646</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;//gridSample (cloud_pass_, *cloud_pass_downsampled_, 0.01);</td></tr>
<tr class="c-line"><td class="code-lc" id="L647"><a href="#L647">647</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cloud_pass_downsampled_ = cloud_pass_;</td></tr>
<tr class="c-line"><td class="code-lc" id="L648"><a href="#L648">648</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;CloudPtr target_cloud;</td></tr>
<tr class="c-line"><td class="code-lc" id="L649"><a href="#L649">649</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;if (use_convex_hull_) {</td></tr>
<tr class="c-line"><td class="code-lc" id="L650"><a href="#L650">650</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;planeSegmentation(cloud_pass_downsampled_, *coefficients,</td></tr>
<tr class="c-line"><td class="code-lc" id="L651"><a href="#L651">651</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*inliers);</td></tr>
<tr class="c-line"><td class="code-lc" id="L652"><a href="#L652">652</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;if (inliers-&gt;indices.size() &gt; 3) {</td></tr>
<tr class="c-line"><td class="code-lc" id="L653"><a href="#L653">653</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;CloudPtr cloud_projected(new Cloud);</td></tr>
<tr class="c-line"><td class="code-lc" id="L654"><a href="#L654">654</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cloud_hull_.reset(new Cloud);</td></tr>
<tr class="c-line"><td class="code-lc" id="L655"><a href="#L655">655</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;nonplane_cloud_.reset(new Cloud);</td></tr>
<tr class="c-line"><td class="code-lc" id="L656"><a href="#L656">656</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L657"><a href="#L657">657</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;planeProjection(cloud_pass_downsampled_, *cloud_projected,</td></tr>
<tr class="c-line"><td class="code-lc" id="L658"><a href="#L658">658</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;coefficients);</td></tr>
<tr class="c-line"><td class="code-lc" id="L659"><a href="#L659">659</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;convexHull(cloud_projected, *cloud_hull_, hull_vertices_);</td></tr>
<tr class="c-line"><td class="code-lc" id="L660"><a href="#L660">660</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L661"><a href="#L661">661</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;extractNonPlanePoints(cloud_pass_downsampled_, cloud_hull_,</td></tr>
<tr class="c-line"><td class="code-lc" id="L662"><a href="#L662">662</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*nonplane_cloud_);</td></tr>
<tr class="c-line"><td class="code-lc" id="L663"><a href="#L663">663</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;target_cloud = nonplane_cloud_;</td></tr>
<tr class="c-line"><td class="code-lc" id="L664"><a href="#L664">664</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;} else {</td></tr>
<tr class="c-line"><td class="code-lc" id="L665"><a href="#L665">665</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;PCL_WARN(&quot;cannot segment plane\n&quot;);</td></tr>
<tr class="c-line"><td class="code-lc" id="L666"><a href="#L666">666</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}</td></tr>
<tr class="c-line"><td class="code-lc" id="L667"><a href="#L667">667</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;} else {</td></tr>
<tr class="c-line"><td class="code-lc" id="L668"><a href="#L668">668</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;PCL_WARN(&quot;without plane segmentation\n&quot;);</td></tr>
<tr class="c-line"><td class="code-lc" id="L669"><a href="#L669">669</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;target_cloud = cloud_pass_downsampled_;</td></tr>
<tr class="c-line"><td class="code-lc" id="L670"><a href="#L670">670</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}</td></tr>
<tr class="c-line"><td class="code-lc" id="L671"><a href="#L671">671</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L672"><a href="#L672">672</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;if (target_cloud != NULL) {</td></tr>
<tr class="c-line"><td class="code-lc" id="L673"><a href="#L673">673</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;PCL_INFO(&quot;segmentation, please wait...\n&quot;);</td></tr>
<tr class="c-line"><td class="code-lc" id="L674"><a href="#L674">674</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;std::vector&lt;pcl::PointIndices&gt; cluster_indices;</td></tr>
<tr class="c-line"><td class="code-lc" id="L675"><a href="#L675">675</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;euclideanSegment(target_cloud, cluster_indices);</td></tr>
<tr class="c-line"><td class="code-lc" id="L676"><a href="#L676">676</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;if (cluster_indices.size() &gt; 0) {</td></tr>
<tr class="c-line"><td class="code-lc" id="L677"><a href="#L677">677</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;// select the cluster to track</td></tr>
<tr class="c-line"><td class="code-lc" id="L678"><a href="#L678">678</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;CloudPtr temp_cloud(new Cloud);</td></tr>
<tr class="c-line"><td class="code-lc" id="L679"><a href="#L679">679</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;extractSegmentCluster(target_cloud, cluster_indices, 0,</td></tr>
<tr class="c-line"><td class="code-lc" id="L680"><a href="#L680">680</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*temp_cloud);</td></tr>
<tr class="c-line"><td class="code-lc" id="L681"><a href="#L681">681</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Eigen::Vector4f c;</td></tr>
<tr class="c-line"><td class="code-lc" id="L682"><a href="#L682">682</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;pcl::compute3DCentroid&lt;RefPointType&gt;(*temp_cloud, c);</td></tr>
<tr class="c-line"><td class="code-lc" id="L683"><a href="#L683">683</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;int segment_index = 0;</td></tr>
<tr class="c-line"><td class="code-lc" id="L684"><a href="#L684">684</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;double segment_distance = c[0] * c[0] + c[1] * c[1];</td></tr>
<tr class="c-line"><td class="code-lc" id="L685"><a href="#L685">685</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;for (size_t i = 1; i &lt; cluster_indices.size(); i++) {</td></tr>
<tr class="c-line"><td class="code-lc" id="L686"><a href="#L686">686</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;temp_cloud.reset(new Cloud);</td></tr>
<tr class="c-line"><td class="code-lc" id="L687"><a href="#L687">687</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;extractSegmentCluster(target_cloud, cluster_indices, i,</td></tr>
<tr class="c-line"><td class="code-lc" id="L688"><a href="#L688">688</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*temp_cloud);</td></tr>
<tr class="c-line"><td class="code-lc" id="L689"><a href="#L689">689</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;pcl::compute3DCentroid&lt;RefPointType&gt;(*temp_cloud, c);</td></tr>
<tr class="c-line"><td class="code-lc" id="L690"><a href="#L690">690</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;double distance = c[0] * c[0] + c[1] * c[1];</td></tr>
<tr class="c-line"><td class="code-lc" id="L691"><a href="#L691">691</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;if (distance &lt; segment_distance) {</td></tr>
<tr class="c-line"><td class="code-lc" id="L692"><a href="#L692">692</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;segment_index = i;</td></tr>
<tr class="c-line"><td class="code-lc" id="L693"><a href="#L693">693</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;segment_distance = distance;</td></tr>
<tr class="c-line"><td class="code-lc" id="L694"><a href="#L694">694</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}</td></tr>
<tr class="c-line"><td class="code-lc" id="L695"><a href="#L695">695</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}</td></tr>
<tr class="c-line"><td class="code-lc" id="L696"><a href="#L696">696</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L697"><a href="#L697">697</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;segmented_cloud_.reset(new Cloud);</td></tr>
<tr class="c-line"><td class="code-lc" id="L698"><a href="#L698">698</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;extractSegmentCluster(target_cloud, cluster_indices,</td></tr>
<tr class="c-line"><td class="code-lc" id="L699"><a href="#L699">699</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;segment_index, *segmented_cloud_);</td></tr>
<tr class="c-line"><td class="code-lc" id="L700"><a href="#L700">700</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;//pcl::PointCloud&lt;pcl::Normal&gt;::Ptr normals (new pcl::PointCloud&lt;pcl::Normal&gt;);</td></tr>
<tr class="c-line"><td class="code-lc" id="L701"><a href="#L701">701</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;//normalEstimation (segmented_cloud_, *normals);</td></tr>
<tr class="c-line"><td class="code-lc" id="L702"><a href="#L702">702</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;RefCloudPtr ref_cloud(new RefCloud);</td></tr>
<tr class="c-line"><td class="code-lc" id="L703"><a href="#L703">703</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;//addNormalToCloud (segmented_cloud_, normals, *ref_cloud);</td></tr>
<tr class="c-line"><td class="code-lc" id="L704"><a href="#L704">704</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ref_cloud = segmented_cloud_;</td></tr>
<tr class="c-line"><td class="code-lc" id="L705"><a href="#L705">705</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;RefCloudPtr nonzero_ref(new RefCloud);</td></tr>
<tr class="c-line"><td class="code-lc" id="L706"><a href="#L706">706</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;removeZeroPoints(ref_cloud, *nonzero_ref);</td></tr>
<tr class="c-line"><td class="code-lc" id="L707"><a href="#L707">707</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L708"><a href="#L708">708</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;PrimitivesExtract&lt;pcl::PointXYZRGBA&gt; prim_ex(nonzero_ref);</td></tr>
<tr class="c-line"><td class="code-lc" id="L709"><a href="#L709">709</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;std::vector&lt;pcl::PointCloud&lt;pcl::PointXYZRGBA&gt;::Ptr&gt; result_vector_lines;</td></tr>
<tr class="c-line"><td class="code-lc" id="L710"><a href="#L710">710</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;std::vector&lt;pcl::PointCloud&lt;pcl::PointXYZRGBA&gt;::Ptr&gt; result_vector_corners;</td></tr>
<tr class="c-line"><td class="code-lc" id="L711"><a href="#L711">711</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;std::vector&lt;pcl::PointCloud&lt;pcl::PointXYZRGBA&gt;::Ptr&gt; result_vector_cylinders;</td></tr>
<tr class="c-line"><td class="code-lc" id="L712"><a href="#L712">712</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;std::vector&lt;pcl::PointCloud&lt;pcl::PointXYZRGBA&gt;::Ptr&gt; result_vector_circles;</td></tr>
<tr class="c-line"><td class="code-lc" id="L713"><a href="#L713">713</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;std::vector&lt;pcl::PointCloud&lt;pcl::PointXYZRGBA&gt;::Ptr&gt; result_vector;</td></tr>
<tr class="c-line"><td class="code-lc" id="L714"><a href="#L714">714</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;std::vector&lt;Eigen::Vector3f&gt; directions_vector;</td></tr>
<tr class="c-line"><td class="code-lc" id="L715"><a href="#L715">715</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L716"><a href="#L716">716</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;std::string what = &quot;rectangular&quot;;</td></tr>
<tr class="c-line"><td class="code-lc" id="L717"><a href="#L717">717</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L718"><a href="#L718">718</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;if (what == &quot;circular&quot;) {</td></tr>
<tr class="c-line"><td class="code-lc" id="L719"><a href="#L719">719</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;prim_ex.extractCylinderVector(nonzero_ref,</td></tr>
<tr class="c-line"><td class="code-lc" id="L720"><a href="#L720">720</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;result_vector_cylinders, 2);</td></tr>
<tr class="c-line"><td class="code-lc" id="L721"><a href="#L721">721</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;prim_ex.extractCircleVector(nonzero_ref,</td></tr>
<tr class="c-line"><td class="code-lc" id="L722"><a href="#L722">722</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;result_vector_circles, 2);</td></tr>
<tr class="c-line"><td class="code-lc" id="L723"><a href="#L723">723</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;PCL_INFO(</td></tr>
<tr class="c-line"><td class="code-lc" id="L724"><a href="#L724">724</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&quot;number of cylinders: %d \n&quot;, result_vector_cylinders.size());</td></tr>
<tr class="c-line"><td class="code-lc" id="L725"><a href="#L725">725</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;PCL_INFO(</td></tr>
<tr class="c-line"><td class="code-lc" id="L726"><a href="#L726">726</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&quot;number of circles: %d \n&quot;, result_vector_circles.size());</td></tr>
<tr class="c-line"><td class="code-lc" id="L727"><a href="#L727">727</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L728"><a href="#L728">728</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;result_vector = result_vector_cylinders;</td></tr>
<tr class="c-line"><td class="code-lc" id="L729"><a href="#L729">729</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;result_vector.insert(result_vector.end(),</td></tr>
<tr class="c-line"><td class="code-lc" id="L730"><a href="#L730">730</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;result_vector_circles.begin(),</td></tr>
<tr class="c-line"><td class="code-lc" id="L731"><a href="#L731">731</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;result_vector_circles.end());</td></tr>
<tr class="c-line"><td class="code-lc" id="L732"><a href="#L732">732</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;} else {</td></tr>
<tr class="c-line"><td class="code-lc" id="L733"><a href="#L733">733</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;prim_ex.extractLineVector(nonzero_ref,</td></tr>
<tr class="c-line"><td class="code-lc" id="L734"><a href="#L734">734</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;result_vector_lines, directions_vector);</td></tr>
<tr class="c-line"><td class="code-lc" id="L735"><a href="#L735">735</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;prim_ex.extractCornerVector(nonzero_ref,</td></tr>
<tr class="c-line"><td class="code-lc" id="L736"><a href="#L736">736</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;result_vector_corners);</td></tr>
<tr class="c-line"><td class="code-lc" id="L737"><a href="#L737">737</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;PCL_INFO(</td></tr>
<tr class="c-line"><td class="code-lc" id="L738"><a href="#L738">738</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&quot;number of lines: %d \n&quot;, result_vector_lines.size());</td></tr>
<tr class="c-line"><td class="code-lc" id="L739"><a href="#L739">739</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;PCL_INFO(</td></tr>
<tr class="c-line"><td class="code-lc" id="L740"><a href="#L740">740</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&quot;number of corners: %d \n&quot;, result_vector_corners.size());</td></tr>
<tr class="c-line"><td class="code-lc" id="L741"><a href="#L741">741</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L742"><a href="#L742">742</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;result_vector = result_vector_lines;</td></tr>
<tr class="c-line"><td class="code-lc" id="L743"><a href="#L743">743</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;result_vector.insert(result_vector.end(),</td></tr>
<tr class="c-line"><td class="code-lc" id="L744"><a href="#L744">744</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;result_vector_corners.begin(),</td></tr>
<tr class="c-line"><td class="code-lc" id="L745"><a href="#L745">745</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;result_vector_corners.end());</td></tr>
<tr class="c-line"><td class="code-lc" id="L746"><a href="#L746">746</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}PCL_INFO(</td></tr>
<tr class="c-line"><td class="code-lc" id="L747"><a href="#L747">747</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&quot;number of features: %d \n&quot;, result_vector.size());</td></tr>
<tr class="c-line"><td class="code-lc" id="L748"><a href="#L748">748</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L749"><a href="#L749">749</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;tracker_vector_.resize(result_vector.size());</td></tr>
<tr class="c-line"><td class="code-lc" id="L750"><a href="#L750">750</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L751"><a href="#L751">751</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;for (int track = 0; track &lt; tracker_vector_.size();</td></tr>
<tr class="c-line"><td class="code-lc" id="L752"><a href="#L752">752</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;track++) {</td></tr>
<tr class="c-line"><td class="code-lc" id="L753"><a href="#L753">753</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L754"><a href="#L754">754</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;RefCloudPtr nonzero_ref_final_cloud(new RefCloud);</td></tr>
<tr class="c-line"><td class="code-lc" id="L755"><a href="#L755">755</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L756"><a href="#L756">756</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;pcl::copyPointCloud(*result_vector[track],</td></tr>
<tr class="c-line"><td class="code-lc" id="L757"><a href="#L757">757</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*nonzero_ref_final_cloud);</td></tr>
<tr class="c-line"><td class="code-lc" id="L758"><a href="#L758">758</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L759"><a href="#L759">759</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;if (track &lt; directions_vector.size()) {</td></tr>
<tr class="c-line"><td class="code-lc" id="L760"><a href="#L760">760</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;directions_vector[track].normalize();</td></tr>
<tr class="c-line"><td class="code-lc" id="L761"><a href="#L761">761</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L762"><a href="#L762">762</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;step_covariance_[0] *= fabs(</td></tr>
<tr class="c-line"><td class="code-lc" id="L763"><a href="#L763">763</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;directions_vector[track][0]);</td></tr>
<tr class="c-line"><td class="code-lc" id="L764"><a href="#L764">764</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;step_covariance_[1] *= fabs(</td></tr>
<tr class="c-line"><td class="code-lc" id="L765"><a href="#L765">765</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;directions_vector[track][1]);</td></tr>
<tr class="c-line"><td class="code-lc" id="L766"><a href="#L766">766</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;step_covariance_[2] *= fabs(</td></tr>
<tr class="c-line"><td class="code-lc" id="L767"><a href="#L767">767</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;directions_vector[track][2]);</td></tr>
<tr class="c-line"><td class="code-lc" id="L768"><a href="#L768">768</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L769"><a href="#L769">769</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;tracker_vector_[track]-&gt;setStepNoiseCovariance(</td></tr>
<tr class="c-line"><td class="code-lc" id="L770"><a href="#L770">770</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;step_covariance_);</td></tr>
<tr class="c-line"><td class="code-lc" id="L771"><a href="#L771">771</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}</td></tr>
<tr class="c-line"><td class="code-lc" id="L772"><a href="#L772">772</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L773"><a href="#L773">773</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;std::stringstream ss;</td></tr>
<tr class="c-line"><td class="code-lc" id="L774"><a href="#L774">774</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ss &lt;&lt; track;</td></tr>
<tr class="c-line"><td class="code-lc" id="L775"><a href="#L775">775</a></td><td class="code mono prettyprint">//                     pcl::io::savePCDFileASCII (ss.str()+&quot;.pcd&quot;, *nonzero_ref_final_cloud);</td></tr>
<tr class="c-line"><td class="code-lc" id="L776"><a href="#L776">776</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L777"><a href="#L777">777</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;PCL_INFO(&quot;calculating cog\n&quot;);</td></tr>
<tr class="c-line"><td class="code-lc" id="L778"><a href="#L778">778</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L779"><a href="#L779">779</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;RefCloudPtr transed_ref(new RefCloud);</td></tr>
<tr class="c-line"><td class="code-lc" id="L780"><a href="#L780">780</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;//pcl::compute3DCentroid&lt;RefPointType&gt; (*nonzero_ref, c);</td></tr>
<tr class="c-line"><td class="code-lc" id="L781"><a href="#L781">781</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;pcl::compute3DCentroid&lt;RefPointType&gt;(</td></tr>
<tr class="c-line"><td class="code-lc" id="L782"><a href="#L782">782</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*nonzero_ref_final_cloud, c);</td></tr>
<tr class="c-line"><td class="code-lc" id="L783"><a href="#L783">783</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L784"><a href="#L784">784</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Eigen::Affine3f trans = Eigen::Affine3f::Identity();</td></tr>
<tr class="c-line"><td class="code-lc" id="L785"><a href="#L785">785</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;trans.translation() = Eigen::Vector3f(c[0], c[1], c[2]);</td></tr>
<tr class="c-line"><td class="code-lc" id="L786"><a href="#L786">786</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;//pcl::transformPointCloudWithNormals&lt;RefPointType&gt; (*ref_cloud, *transed_ref, trans.inverse());</td></tr>
<tr class="c-line"><td class="code-lc" id="L787"><a href="#L787">787</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;//pcl::transformPointCloud&lt;RefPointType&gt; (*nonzero_ref, *transed_ref, trans.inverse());</td></tr>
<tr class="c-line"><td class="code-lc" id="L788"><a href="#L788">788</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;pcl::transformPointCloud&lt;RefPointType&gt;(</td></tr>
<tr class="c-line"><td class="code-lc" id="L789"><a href="#L789">789</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*nonzero_ref_final_cloud, *transed_ref,</td></tr>
<tr class="c-line"><td class="code-lc" id="L790"><a href="#L790">790</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;trans.inverse());</td></tr>
<tr class="c-line"><td class="code-lc" id="L791"><a href="#L791">791</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L792"><a href="#L792">792</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;CloudPtr transed_ref_downsampled(new Cloud);</td></tr>
<tr class="c-line"><td class="code-lc" id="L793"><a href="#L793">793</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;gridSample(transed_ref, *transed_ref_downsampled,</td></tr>
<tr class="c-line"><td class="code-lc" id="L794"><a href="#L794">794</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;downsampling_grid_size_);</td></tr>
<tr class="c-line"><td class="code-lc" id="L795"><a href="#L795">795</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;tracker_vector_[track]-&gt;setReferenceCloud(</td></tr>
<tr class="c-line"><td class="code-lc" id="L796"><a href="#L796">796</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;transed_ref_downsampled);</td></tr>
<tr class="c-line"><td class="code-lc" id="L797"><a href="#L797">797</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;tracker_vector_[track]-&gt;setTrans(trans);</td></tr>
<tr class="c-line"><td class="code-lc" id="L798"><a href="#L798">798</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;reference_ = transed_ref;</td></tr>
<tr class="c-line"><td class="code-lc" id="L799"><a href="#L799">799</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;tracker_vector_[track]-&gt;setMinIndices(</td></tr>
<tr class="c-line"><td class="code-lc" id="L800"><a href="#L800">800</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ref_cloud-&gt;points.size() / 2);</td></tr>
<tr class="c-line"><td class="code-lc" id="L801"><a href="#L801">801</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}</td></tr>
<tr class="c-line"><td class="code-lc" id="L802"><a href="#L802">802</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;} else {</td></tr>
<tr class="c-line"><td class="code-lc" id="L803"><a href="#L803">803</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;PCL_WARN(&quot;euclidean segmentation failed\n&quot;);</td></tr>
<tr class="c-line"><td class="code-lc" id="L804"><a href="#L804">804</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}</td></tr>
<tr class="c-line"><td class="code-lc" id="L805"><a href="#L805">805</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L806"><a href="#L806">806</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}</td></tr>
<tr class="c-line"><td class="code-lc" id="L807"><a href="#L807">807</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;} else {</td></tr>
<tr class="c-line"><td class="code-lc" id="L808"><a href="#L808">808</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;//normals_.reset (new pcl::PointCloud&lt;pcl::Normal&gt;);</td></tr>
<tr class="c-line"><td class="code-lc" id="L809"><a href="#L809">809</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;//normalEstimation (cloud_pass_downsampled_, *normals_);</td></tr>
<tr class="c-line"><td class="code-lc" id="L810"><a href="#L810">810</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;//RefCloudPtr tracking_cloud (new RefCloud ());</td></tr>
<tr class="c-line"><td class="code-lc" id="L811"><a href="#L811">811</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;//addNormalToCloud (cloud_pass_downsampled_, normals_, *tracking_cloud);</td></tr>
<tr class="c-line"><td class="code-lc" id="L812"><a href="#L812">812</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;//tracking_cloud = cloud_pass_downsampled_;</td></tr>
<tr class="c-line"><td class="code-lc" id="L813"><a href="#L813">813</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L814"><a href="#L814">814</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;//*cloud_pass_downsampled_ = *cloud_pass_;</td></tr>
<tr class="c-line"><td class="code-lc" id="L815"><a href="#L815">815</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;//cloud_pass_downsampled_ = cloud_pass_;</td></tr>
<tr class="c-line"><td class="code-lc" id="L816"><a href="#L816">816</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;gridSampleApprox(cloud_pass_, *cloud_pass_downsampled_,</td></tr>
<tr class="c-line"><td class="code-lc" id="L817"><a href="#L817">817</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;downsampling_grid_size_);</td></tr>
<tr class="c-line"><td class="code-lc" id="L818"><a href="#L818">818</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;tracking(cloud_pass_downsampled_);</td></tr>
<tr class="c-line"><td class="code-lc" id="L819"><a href="#L819">819</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}</td></tr>
<tr class="c-line"><td class="code-lc" id="L820"><a href="#L820">820</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L821"><a href="#L821">821</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;new_cloud_ = true;</td></tr>
<tr class="c-line"><td class="code-lc" id="L822"><a href="#L822">822</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;double end = pcl::getTime();</td></tr>
<tr class="c-line"><td class="code-lc" id="L823"><a href="#L823">823</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;computation_time_ = end - start;</td></tr>
<tr class="c-line"><td class="code-lc" id="L824"><a href="#L824">824</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;FPS_CALC_END(&quot;computation&quot;);</td></tr>
<tr class="c-line"><td class="code-lc" id="L825"><a href="#L825">825</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;if (cloud_intensity_ != NULL) {</td></tr>
<tr class="c-line"><td class="code-lc" id="L826"><a href="#L826">826</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L827"><a href="#L827">827</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}</td></tr>
<tr class="c-line"><td class="code-lc" id="L828"><a href="#L828">828</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;counter_++;</td></tr>
<tr class="c-line"><td class="code-lc" id="L829"><a href="#L829">829</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L830"><a href="#L830">830</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;}</td></tr>
<tr class="c-line"><td class="code-lc" id="L831"><a href="#L831">831</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L832"><a href="#L832">832</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;void run() {</td></tr>
<tr class="c-line"><td class="code-lc" id="L833"><a href="#L833">833</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;pcl::Grabber* interface = new pcl::OpenNIGrabber(device_id_);</td></tr>
<tr class="c-line"><td class="code-lc" id="L834"><a href="#L834">834</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;boost::function&lt;void(const CloudConstPtr&amp;)&gt; f = boost::bind(</td></tr>
<tr class="c-line"><td class="code-lc" id="L835"><a href="#L835">835</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&amp;OpenNISegmentTracking::cloud_cb, this, _1);</td></tr>
<tr class="c-line"><td class="code-lc" id="L836"><a href="#L836">836</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;interface-&gt;registerCallback(f);</td></tr>
<tr class="c-line"><td class="code-lc" id="L837"><a href="#L837">837</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L838"><a href="#L838">838</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;viewer_.runOnVisualizationThread(</td></tr>
<tr class="c-line"><td class="code-lc" id="L839"><a href="#L839">839</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;boost::bind(&amp;OpenNISegmentTracking::viz_cb, this, _1),</td></tr>
<tr class="c-line"><td class="code-lc" id="L840"><a href="#L840">840</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&quot;viz_cb&quot;);</td></tr>
<tr class="c-line"><td class="code-lc" id="L841"><a href="#L841">841</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L842"><a href="#L842">842</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;interface-&gt;start();</td></tr>
<tr class="c-line"><td class="code-lc" id="L843"><a href="#L843">843</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L844"><a href="#L844">844</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;while (!viewer_.wasStopped())</td></tr>
<tr class="c-line"><td class="code-lc" id="L845"><a href="#L845">845</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;boost::this_thread::sleep(boost::posix_time::seconds(1));</td></tr>
<tr class="c-line"><td class="code-lc" id="L846"><a href="#L846">846</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;interface-&gt;stop();</td></tr>
<tr class="c-line"><td class="code-lc" id="L847"><a href="#L847">847</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;a_file_.close();</td></tr>
<tr class="c-line"><td class="code-lc" id="L848"><a href="#L848">848</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L849"><a href="#L849">849</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;}</td></tr>
<tr class="c-line"><td class="code-lc" id="L850"><a href="#L850">850</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L851"><a href="#L851">851</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;pcl::visualization::CloudViewer viewer_;</td></tr>
<tr class="c-line"><td class="code-lc" id="L852"><a href="#L852">852</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;pcl::PointCloud&lt;pcl::Normal&gt;::Ptr normals_;</td></tr>
<tr class="c-line"><td class="code-lc" id="L853"><a href="#L853">853</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;CloudPtr cloud_pass_;</td></tr>
<tr class="c-line"><td class="code-lc" id="L854"><a href="#L854">854</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;CloudPtr cloud_pass_downsampled_;</td></tr>
<tr class="c-line"><td class="code-lc" id="L855"><a href="#L855">855</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;CloudPtr plane_cloud_;</td></tr>
<tr class="c-line"><td class="code-lc" id="L856"><a href="#L856">856</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;CloudPtr nonplane_cloud_;</td></tr>
<tr class="c-line"><td class="code-lc" id="L857"><a href="#L857">857</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;CloudPtr cloud_hull_;</td></tr>
<tr class="c-line"><td class="code-lc" id="L858"><a href="#L858">858</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;CloudPtr segmented_cloud_;</td></tr>
<tr class="c-line"><td class="code-lc" id="L859"><a href="#L859">859</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;CloudPtr reference_;</td></tr>
<tr class="c-line"><td class="code-lc" id="L860"><a href="#L860">860</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L861"><a href="#L861">861</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;pcl::PointCloud&lt;pcl::PointXYZI&gt;::Ptr cloud_intensity_;</td></tr>
<tr class="c-line"><td class="code-lc" id="L862"><a href="#L862">862</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L863"><a href="#L863">863</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;Eigen::Affine3f transformation_;</td></tr>
<tr class="c-line"><td class="code-lc" id="L864"><a href="#L864">864</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L865"><a href="#L865">865</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;std::vector&lt;pcl::Vertices&gt; hull_vertices_;</td></tr>
<tr class="c-line"><td class="code-lc" id="L866"><a href="#L866">866</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L867"><a href="#L867">867</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;std::string device_id_;</td></tr>
<tr class="c-line"><td class="code-lc" id="L868"><a href="#L868">868</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;boost::mutex mtx_;</td></tr>
<tr class="c-line"><td class="code-lc" id="L869"><a href="#L869">869</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;bool new_cloud_;</td></tr>
<tr class="c-line"><td class="code-lc" id="L870"><a href="#L870">870</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;pcl::NormalEstimationOMP&lt;PointType, pcl::Normal&gt; ne_; // to store threadpool</td></tr>
<tr class="c-line"><td class="code-lc" id="L871"><a href="#L871">871</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;boost::shared_ptr&lt;ParticleFilter&gt; tracker_;</td></tr>
<tr class="c-line"><td class="code-lc" id="L872"><a href="#L872">872</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;std::vector&lt;boost::shared_ptr&lt;ParticleFilter&gt; &gt; tracker_vector_;</td></tr>
<tr class="c-line"><td class="code-lc" id="L873"><a href="#L873">873</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;std::vector&lt;double&gt; step_covariance_;</td></tr>
<tr class="c-line"><td class="code-lc" id="L874"><a href="#L874">874</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;int counter_;</td></tr>
<tr class="c-line"><td class="code-lc" id="L875"><a href="#L875">875</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;bool use_convex_hull_;</td></tr>
<tr class="c-line"><td class="code-lc" id="L876"><a href="#L876">876</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;bool visualize_non_downsample_;</td></tr>
<tr class="c-line"><td class="code-lc" id="L877"><a href="#L877">877</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;bool visualize_particles_;</td></tr>
<tr class="c-line"><td class="code-lc" id="L878"><a href="#L878">878</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;double tracking_time_;</td></tr>
<tr class="c-line"><td class="code-lc" id="L879"><a href="#L879">879</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;double computation_time_;</td></tr>
<tr class="c-line"><td class="code-lc" id="L880"><a href="#L880">880</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;double downsampling_time_;</td></tr>
<tr class="c-line"><td class="code-lc" id="L881"><a href="#L881">881</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;double downsampling_grid_size_;</td></tr>
<tr class="c-line"><td class="code-lc" id="L882"><a href="#L882">882</a></td><td class="code mono prettyprint">&nbsp;&nbsp;&nbsp;&nbsp;std::ofstream a_file_;</td></tr>
<tr class="c-line"><td class="code-lc" id="L883"><a href="#L883">883</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L884"><a href="#L884">884</a></td><td class="code mono prettyprint">};</td></tr>
<tr class="c-line"><td class="code-lc" id="L885"><a href="#L885">885</a></td><td class="code mono prettyprint"></td></tr>
<tr class="c-line"><td class="code-lc" id="L886"><a href="#L886">886</a></td><td class="code mono prettyprint"></td></tr>
</tbody>
</table>

<p class="right soft"><a href="/indefero/index.php//p/seie2011fall/source/file/HEAD/hausman/3d-tracking-lines/3d_tracking_lines.cpp"><img style="vertical-align: text-bottom;" src="http://code.in.tum.de/indefero/media/idf/img/package-grey.png" alt="Archive" align="bottom" /></a> <a href="/indefero/index.php//p/seie2011fall/source/file/HEAD/hausman/3d-tracking-lines/3d_tracking_lines.cpp">Download this file</a></p>

</div>
	</div>
      </div>
    </div>
    <div class="yui-b context">
<form class="star" action="/indefero/index.php//p/seie2011fall/source/treerev/" method="get">
<p><strong>Revision:</strong> HEAD</p>
<p>
    <input accesskey="4" type="text" value="HEAD" name="rev" size="5" />
    <input type="hidden" name="sourcefile" value="3d_tracking_lines.cpp"/>
    <input type="submit" name="s" value="Go to revision" /></p>
  </form>
</div>
  </div>
  <div id="ft"></div>
</div>
<script type="text/javascript" src="http://code.in.tum.de/indefero/media/idf/js/jquery-1.2.6.min.js"></script>
<script type="text/javascript" src="http://code.in.tum.de/indefero/media/idf/js/jquery.hotkeys.js"></script>
<script type="text/javascript" charset="utf-8">
// <!--
jQuery.hotkeys.add('Shift+h',{disableInInput: true},function (){window.location.href='/indefero/index.php//help/';});

jQuery.hotkeys.add('Shift+u',{disableInInput: true},function (){window.location.href='/indefero/index.php//p/seie2011fall/timeline/';});
jQuery.hotkeys.add('Shift+a',{disableInInput: true},function (){window.location.href='/indefero/index.php//p/seie2011fall/issues/create/';});
jQuery.hotkeys.add('Shift+i',{disableInInput: true},function (){window.location.href='/indefero/index.php//p/seie2011fall/issues/';});
jQuery.hotkeys.add('Shift+d',{disableInInput: true},function (){window.location.href='/indefero/index.php//p/seie2011fall/downloads/';});
jQuery.hotkeys.add('Shift+o',{disableInInput: true},function (){window.location.href='/indefero/index.php//p/seie2011fall/doc/';});
jQuery.hotkeys.add('Shift+s',{disableInInput: true},function (){window.location.href='/indefero/index.php//p/seie2011fall/source/tree/HEAD/';});
 //-->
</script>



<script type="text/javascript" src="http://code.in.tum.de/indefero/media/idf/js/prettify.js"></script>
<script type="text/javascript">prettyPrint();</script>


<script type="text/javascript" charset="utf-8">
//<![CDATA[
$(document).ready(function(){
	var frag = location.hash;
	if ($('#preview').length) {
		location.hash = '#preview';
	}
	else if (frag.length > 3 && frag.substring(0, 3) == '#ic') {
		$(frag).addClass("issue-comment-focus");
	}
});
//]]>
</script>
</body>
</html>
