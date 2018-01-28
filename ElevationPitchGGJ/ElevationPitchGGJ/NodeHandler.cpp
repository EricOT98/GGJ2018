#include "NodeHandler.h"

NodeHandler::NodeHandler()
{

}

NodeHandler::~NodeHandler()
{
}

void NodeHandler::update()
{
	for (auto & node : m_nodes) {
		if (node.withinBounds(m_position, m_size)) {
			node.setAlive(false);
		}
		if (node.getAlive()) {
			node.update();
		}
	}
}

void NodeHandler::render(sf::RenderWindow & window)
{
	for (auto & node : m_nodes) {
		if (node.getAlive()) {
			node.render(window);
		}
	}
	for (auto & line : m_lines) {
		window.draw(line);
	}
}

void NodeHandler::init(sf::Vector2f pos, sf::Vector2f & windowSize, int numColumns)
{
	m_position = pos;
	m_size = sf::Vector2f(windowSize.x / 2.0f, windowSize.y);
	m_columnWidth = (m_size.x) / numColumns;
	//m_size = sf::Vector2f(windowSize.x / 2.0f, windowSize.y);
	for (int i = 0; i < numColumns + 1; ++i) {
		m_positions.push_back(pos.x + (i * m_columnWidth));
		sf::VertexArray m_line(sf::Lines, 2);
		m_line[0].position = sf::Vector2f(m_positions.at(i),0 );
		m_line[1].position = sf::Vector2f(m_positions.at(i), windowSize.y);
		m_line[0].color = sf::Color::Red;
		m_line[1].color = sf::Color::Red;
		m_lines.push_back(m_line);
	}

	std::srand(0);
}

sf::Vector2f NodeHandler::getNodeSize()
{
	return sf::Vector2f(m_size);
}

void NodeHandler::populate(int numNodes)
{
	for (int i = 0; i < numNodes; ++i) {
		m_nodes.push_back(Node());
	}
}

bool NodeHandler::spawnNode(sf::Vector2f pos, sf::Vector2f size, sf::Color col, int column)
{
	for (int i = 0; i < m_nodes.size(); ++i) {
		if (!m_nodes.at(i).getAlive()) {
			m_nodes.at(i).spawn(pos, size, col, 5, column);
			return true;
		}
	}
	return false;
}

void NodeHandler::randomGeneration(sf::Vector2f size)
{
	int numPositions = m_positions.size();
	sf::Color col(std::rand() % 256, std::rand() % 256, std::rand() % 256, 255);
	int columnToSpawn = std::rand() % (numPositions - 1);
	spawnNode(sf::Vector2f(m_positions.at(columnToSpawn), m_size.y), sf::Vector2f(m_columnWidth, size.y), col, columnToSpawn);
}

int NodeHandler::getNumPositions()
{
	return m_positions.size();
}

bool NodeHandler::collision(sf::Vector2f & p_pos, sf::Vector2f & p_size, Node & node)
{
	sf::Vector2f n_size = node.getSize();
	sf::Vector2f n_pos = node.getPosition();
	return !(p_pos.x + p_size.x <n_pos.x ||
		p_pos.x > n_pos.x + n_size.x ||
		p_pos.y + p_size.y < n_pos.y ||
		p_pos.y > n_pos.y + n_size.y);
}
void NodeHandler::setSpeed(float speed)
{
	for (auto & node : m_nodes) {
		node.m_speed = speed;
	}
}
